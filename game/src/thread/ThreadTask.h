//
// Created by Wesly Zhong on 2025/10/12.
//

#ifndef ATHENA_THREADTASK_H
#define ATHENA_THREADTASK_H

#include"common/ThreadPool.h"


class ThreadTask : public Thread::Task{
public:
     void process() ;

     void complete() ;
};


#endif //ATHENA_THREADTASK_H
