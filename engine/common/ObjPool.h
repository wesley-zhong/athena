//
// Created by zhongweiqi on 2025/10/14.
//

#ifndef ATHENA_OBJPOOL_H
#define ATHENA_OBJPOOL_H
#include <vector>
#include <stack>
#include <memory>
#include <mutex>
#include <utility>
#include <atomic>
#include <chrono>
#include "XLog.h"

template<typename T>
class ObjPool {
private:
    struct Node {
        T *obj;
        Node *next;
    };

    // lock-free stacks
    std::atomic<Node *> _head{nullptr}; // free objects
    std::atomic<Node *> _nodePool{nullptr}; // free nodes

    std::vector<std::unique_ptr<T> > _ownedObjects;
    std::vector<std::unique_ptr<Node> > _ownedNodes;
    std::mutex _allocMutex;

    // stats
    std::atomic<size_t> _freeCount{0};
    std::atomic<size_t> _allocCountObj{0};
    std::atomic<size_t> _allocCountNode{0};
    std::atomic<size_t> _hitCount{0};
    std::atomic<size_t> _missCount{0};

    size_t _maxSize = 0; // 0 = unlimited
    bool _debug = false;

public:
    class PoolObjPtr;

    explicit ObjPool(size_t initial = 0, size_t maxSize = 0)
        : _maxSize(maxSize) {
        //reserve(initial);
    }

    ~ObjPool() {
        _head.store(nullptr);
        _nodePool.store(nullptr);
    }

    void setDebug(bool enabled) noexcept { _debug = enabled; }

    // 初始化预分配
    void reserve(size_t n) {
        for (size_t i = 0; i < n; ++i) {
            auto objUP = std::make_unique<T>();
            T *obj = objUP.get();

            auto nodeUP = std::make_unique<Node>();
            Node *node = nodeUP.get();
            node->obj = obj;
            node->next = nullptr;

            {
                std::lock_guard<std::mutex> lk(_allocMutex);
                _ownedObjects.push_back(std::move(objUP));
                _ownedNodes.push_back(std::move(nodeUP));
            }

            pushNodeToHead(node);
            _freeCount.fetch_add(1, std::memory_order_relaxed);
            _allocCountObj.fetch_add(1, std::memory_order_relaxed);
            _allocCountNode.fetch_add(1, std::memory_order_relaxed);
        }
    }

    template<typename... Args>
    PoolObjPtr acquire(Args &&... args) {
        Node *n = popNodeFromHead();
        if (n) {
            _freeCount.fetch_sub(1, std::memory_order_relaxed);
            _hitCount.fetch_add(1, std::memory_order_relaxed);
            T *obj = n->obj;
            obj->~T();
            new(obj) T(std::forward<Args>(args)...);
            if (_debug) {
                //  INFO_LOG("[Pool] Hit, reuse obj {} ", *obj);
            }
            return PoolObjPtr(obj, this);
        }
        _missCount.fetch_add(1, std::memory_order_relaxed);
        auto up = std::make_unique<T>(std::forward<Args>(args)...);
        T *obj = up.get();
        {
            std::lock_guard<std::mutex> lk(_allocMutex);
            _ownedObjects.push_back(std::move(up));
        }
        _allocCountObj.fetch_add(1, std::memory_order_relaxed);
        if (_debug) {
            // INFO_LOG("[Pool] Miss, new obj {} ", *obj);
        }
        return PoolObjPtr(obj, this);
    }

    template<typename... Args>
    std::shared_ptr<T> acquirePtr(Args &&... args) {
        Node *n = popNodeFromHead();
        if (n) {
            _freeCount.fetch_sub(1, std::memory_order_relaxed);
            _hitCount.fetch_add(1, std::memory_order_relaxed);
            T *obj = n->obj;
            obj->~T();
            new(obj) T(std::forward<Args>(args)...);
            if (_debug) {
                //  INFO_LOG("[Pool] Hit, reuse obj {} ", *obj);
            }
            return std::shared_ptr<T>(obj);
        }
        _missCount.fetch_add(1, std::memory_order_relaxed);
        auto up = std::make_unique<T>(std::forward<Args>(args)...);
        T *obj = up.get();
        {
            std::lock_guard<std::mutex> lk(_allocMutex);
            _ownedObjects.push_back(std::move(up));
        }
        _allocCountObj.fetch_add(1, std::memory_order_relaxed);
        if (_debug) {
            // INFO_LOG("[Pool] Miss, new obj {} ", *obj);
        }
        return std::shared_ptr<T>(obj);
    }

    void release(T *obj, bool callDestructure = true) noexcept {
        if (!obj) return;
        if (callDestructure) {
            obj->~T();
        }
      //  new(obj) T();

        size_t freeNow = _freeCount.load(std::memory_order_relaxed);
        if (_maxSize > 0 && freeNow >= _maxSize) {
            INFO_LOG("[Pool] Drop obj {}  maxSize reached", fmt::ptr(obj));
            return;
        }

        Node *node = popNodeFromNodePool();
        if (!node) {
            auto nodeUP = std::make_unique<Node>();
            node = nodeUP.get();
            {
                std::lock_guard<std::mutex> lk(_allocMutex);
                _ownedNodes.push_back(std::move(nodeUP));
            }
            _allocCountNode.fetch_add(1, std::memory_order_relaxed);
        }
        node->obj = obj;
        node->next = nullptr;

        pushNodeToHead(node);
        _freeCount.fetch_add(1, std::memory_order_relaxed);
        INFO_LOG("[Pool] Release obj {} back to pool", fmt::ptr(obj));
    }

    // ===== 统计接口 =====
    size_t freeCount() const noexcept { return _freeCount.load(); }
    size_t maxSize() const noexcept { return _maxSize; }
    size_t hitCount() const noexcept { return _hitCount.load(); }
    size_t missCount() const noexcept { return _missCount.load(); }
    size_t allocCountObj() const noexcept { return _allocCountObj.load(); }
    size_t allocCountNode() const noexcept { return _allocCountNode.load(); }

    void printStats() const {
        INFO_LOG("==== ObjectPool Stats ====");
        INFO_LOG("freeCount     :   {} ", freeCount());
        INFO_LOG("hitCount      :   {}  ", hitCount());
        INFO_LOG("missCount     :   {} ", missCount());
        INFO_LOG("allocCountObj :   {} ", allocCountObj());
        INFO_LOG("allocCountNode:   {} ", allocCountNode());
        INFO_LOG("==========================");
    }

private:
    // lock-free stack helpers
    void pushNodeToHead(Node *node) noexcept {
        Node *old = _head.load(std::memory_order_relaxed);
        do { node->next = old; } while (!_head.compare_exchange_weak(old, node,
                                                                     std::memory_order_release,
                                                                     std::memory_order_relaxed));
    }

    Node *popNodeFromHead() noexcept {
        Node *head = _head.load(std::memory_order_acquire);
        while (head) {
            Node *next = head->next;
            if (_head.compare_exchange_weak(head, next,
                                            std::memory_order_acquire,
                                            std::memory_order_relaxed)) {
                return head;
            }
        }
        return nullptr;
    }

    void pushNodeToNodePool(Node *node) noexcept {
        Node *old = _nodePool.load(std::memory_order_relaxed);
        do { node->next = old; } while (!_nodePool.compare_exchange_weak(old, node,
                                                                         std::memory_order_release,
                                                                         std::memory_order_relaxed));
    }

    Node *popNodeFromNodePool() noexcept {
        Node *head = _nodePool.load(std::memory_order_acquire);
        while (head) {
            Node *next = head->next;
            if (_nodePool.compare_exchange_weak(head, next,
                                                std::memory_order_acquire,
                                                std::memory_order_relaxed)) {
                return head;
            }
        }
        return nullptr;
    }
};

// RAII handle
template<typename T>
class ObjPool<T>::PoolObjPtr {
public:
    PoolObjPtr() noexcept : _obj(nullptr), _pool(nullptr) {
    }

    PoolObjPtr(T *obj, ObjPool *pool) noexcept : _obj(obj), _pool(pool) {
    }

    PoolObjPtr(const PoolObjPtr &) = delete;

    PoolObjPtr &operator=(const PoolObjPtr &) = delete;

    PoolObjPtr(PoolObjPtr &&o) noexcept : _obj(o._obj), _pool(o._pool) {
        o._obj = nullptr;
        o._pool = nullptr;
    }

    PoolObjPtr &operator=(PoolObjPtr &&o) noexcept {
        if (this != &o) {
            release();
            _obj = o._obj;
            _pool = o._pool;
            o._obj = nullptr;
            o._pool = nullptr;
        }
        return *this;
    }

    ~PoolObjPtr() { release(); }

    T *operator->() const noexcept { return _obj; }
    T &operator*() const noexcept { return *_obj; }
    T *get() const noexcept { return _obj; }
    explicit operator bool() const noexcept { return _obj != nullptr; }

    void release() noexcept {
        if (_obj && _pool) {
            _pool->release(_obj);
            _obj = nullptr;
            _pool = nullptr;
        }
    }

private:
    T *_obj;
    ObjPool *_pool;
};


#endif //ATHENA_OBJPOOL_H
