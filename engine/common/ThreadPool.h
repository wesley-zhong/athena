#pragma once

#include <vector>
#include <thread>
#include "TQueue.h"
#include "ObjectPool.h"
#include "XLog.h"
#include "BaseType.h"
#include "ObjectPool.hpp"

namespace Thread {
    class ITask {
    public:
        virtual ~ITask();

        virtual void run() = 0;
    };
    typedef  std::unique_ptr<ITask> TaskPtr;

    class RunTask : public ITask {
    public:
        explicit RunTask(const VOID_FUN &func) : _func(std::move(func)) {
        }

        explicit RunTask() {
        }

        void run() override {
            _func();
        }

        ~RunTask() override {
            ObjPool::release<RunTask>(this, false);
        }

        static TaskPtr create(const VOID_FUN &func) {
            return ObjPool::acquireUniquePtr<RunTask>(func);
        }

    private:
        VOID_FUN _func;
    };





    class ThreadPool;

    class Worker {
    public:
        Worker();

        virtual ~Worker();

        static void thread_func(Worker *t);

        void stop();

        void execute(TaskPtr task);

        virtual void run(TaskPtr task);

    protected:
        virtual void onStart() {
        };

        virtual void onEnd() {
        };

    protected:
        TaskPtr popWaitTask();

        std::thread _thread;
        std::atomic<bool> _isrun{true};
        TQueue<TaskPtr> _waitTasks;
    };

    class ThreadPool {
    public:
        ThreadPool();

        virtual ~ThreadPool();

        void create(int count);

        void exit();

        void executeTask(TaskPtr task, int threadHashCode = 0) const;


        void execute(const VOID_FUN &run, int threadHashCode = 0) {
            int threadIndex = threadHashCode % (int) _threads.size();
            auto it = RunTask::create((VOID_FUN)run);
            _threads[threadIndex]->execute(std::move(it));
        }

    protected:
        virtual Worker *createThread() = 0;

        virtual void deleteThread(Worker *t) {
            auto it = std::find(_threads.begin(), _threads.end(), t);
            if (it != _threads.end()) {
                _threads.erase(it);
            }
        }

    private:
        std::vector<Worker *> _threads;
    };
}
