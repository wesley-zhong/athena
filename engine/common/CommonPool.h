#pragma once
#include "BaseType.h"
#include "Objectpool.h"
#include "Singleton.h"

template<typename T>
class CommonPool : public Singleton<CommonPool<T>>
{
public:
    using Ptr = std::unique_ptr<T, std::function<void(T*)>>;
    void init(int maxCount, int initCount){
        objpool = new ObjectPool<T>(maxCount, initCount);
    }
    Ptr acquire(){
        return  objpool->acquire();
    }
    T * create(){
        return objpool->create();
    }
    void release(T* obj){
        objpool->release(obj);
    }
    size_t size(){
        return  objpool->size();
    }

private:
	ObjectPool<T> *objpool ;
};

namespace ObjPool{
    template <typename T>
    using UniquePtr = std::unique_ptr<T, std::function<void(T*)>>;

    template<typename T>
    void init(int count){
        CommonPool<T>::Instance()->init(count,count);
    }

    template<typename T>
    size_t  size(){
        return CommonPool<T>::Instance()->size();
    }

    template<typename T>
    T * create()
    {
       return  CommonPool<T>::Instance()->create();
     //   obj->zero();
       // return obj;
    }
    template<typename T>
    UniquePtr<T> acquire(){
        return CommonPool<T>::Instance()->acquire();
    }
    template<typename T>
    void release(T* obj){
        return CommonPool<T>::Instance()->release(obj);
    }




}