//
// Created by Wesly Zhong on 2025/10/12.
//

#include "AthenaThreadPool.h"
Thread::CThread *AthenaThreadPool::createThread(){
    return new Thread::CThread();

}

void AthenaThreadPool::deleteThread(Thread::CThread *t){

}

void AthenaThreadPool::completeTask(Thread::TaskPtr task) {

}