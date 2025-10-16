//
// Created by zhongweiqi on 2025/10/16.
//
#pragma once

#include "ObjectPool.h"

namespace ObjPool {
    template<typename T>
    ObjectPool<T> &getPool() {
        static ObjectPool<T> s_pool(0, 1024);
        return s_pool;
    }


    template<typename T, typename... Args>
    typename ObjectPool<T>::PoolObjPtr acquire(Args &&... args) {
        return getPool<T>().acquire(std::forward<Args>(args)...);
    }

    template<typename T, typename... Args>
    T *acquirePtr(Args &&... args) {
        return getPool<T>().acquirePtr(std::forward<Args>(args)...);
    }

    template<typename T>
    void release(T *ptr, bool callDestructure) {
        getPool<T>().release(ptr, callDestructure);
    }

    template<typename T, typename... Args>
    std::unique_ptr<T> acquireUniquePtr(Args &&... args) {
        return getPool<T>().acquireUniquePtr(std::forward<Args>(args)...);
    }
}
