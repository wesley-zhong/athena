#ifndef _OBJECT_POOL_H
#define _OBJECT_POOL_H

#include <functional>
#include <stack>
#include "XAssert.h"
#include "XLog.h"

template< typename T>
class ObjectPool
{
public:
    using Ptr = std::unique_ptr<T, std::function<void(T*)>>;
    ObjectPool(int maxCount, size_t initSize = 10):maxCount(maxCount),borrowedCount(0) {
        for (size_t i = 0; i < initSize; ++i) {
            freeObjects.push(new T());
        }
    }

    ~ObjectPool() {
        while (!freeObjects.empty()) {
            delete freeObjects.top();
            freeObjects.pop();
        }
    }

    // 从池子获取对象
    Ptr acquire() {
        if(!freeObjects.empty()){
            T* obj = freeObjects.top();
            freeObjects.pop();
            borrowedCount++;
            return Ptr(obj, [this](T* obj) { this->release(obj);});
        }
        if(borrowedCount < maxCount){
            borrowedCount++;
            return Ptr(new T(), [this](T* obj) { this->release(obj);});
        }
        ERR_LOG("no enough  space");
    }

    // note: this should be release manually
    T*  create(){
        if(!freeObjects.empty()){
            T* obj = freeObjects.top();
            freeObjects.pop();
            borrowedCount++;
            return obj;
        }
        if(borrowedCount < maxCount){
            borrowedCount++;
            return new T();
        }
        ERR_LOG("no enough  space");
    }
    // 回收对象放回池子
    void release(T* obj) {
        borrowedCount--;
        freeObjects.push(obj);
    }
    size_t  size(){
        return maxCount - borrowedCount;
    }

private:
    std::stack<T*> freeObjects;
    int maxCount;
    int borrowedCount;
};


#endif