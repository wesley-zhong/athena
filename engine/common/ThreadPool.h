#pragma once

#include <vector>
#include <thread>
#include "TQueue.h"

namespace Thread {
    class Task {
    public:
        virtual ~Task();

        virtual void process() = 0;

        virtual void complete() = 0;
    };

    typedef std::shared_ptr<Task> TaskPtr;

    class ThreadPool;

    class CThread {
    public:
        CThread();

        virtual ~CThread();

        static void thread_func(CThread *t);

        void stop();

        void executeTask(TaskPtr task);

        virtual void run(TaskPtr task);

    protected:
        virtual void onStart() {};

        virtual void onEnd() {};

    protected:
        std::thread _thread;
        std::atomic<bool> _isrun{true};
        TQueue<TaskPtr> _waitTasks;

        TaskPtr popWaitTask();
    };

    class ThreadPool {
    public:
        ThreadPool();

        virtual ~ThreadPool();

        void create(int count);

        void exit();

        void addTask(TaskPtr task, int threadHashCode =0);

        void update();

    protected:
        virtual CThread *createThread() = 0;

        virtual void deleteThread(CThread *t) = 0;

        virtual void completeTask(TaskPtr task) = 0;

    private:
        std::vector<CThread *> _threads;
        //  TQueue<TaskPtr> _waitTasks;
        TQueue<TaskPtr> _completeTasks;
    };
}

