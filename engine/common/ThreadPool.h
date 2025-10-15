#pragma once

#include <vector>
#include <thread>
#include "TQueue.h"
#include "ObjPool.h"
#include "XLog.h"

namespace Thread {
    class ITask {
    public:
        virtual ~ITask();

        virtual void run() = 0;
    };

    template<typename F>
    class TaskImpl : public ITask {
    public:
        explicit TaskImpl(F &&f) : func_(std::forward<F>(f)) {
        }

        explicit TaskImpl(F &f) : func_(std::forward<F>(f)) {
        }


        void run() override { func_(); }

        ~TaskImpl() override {
            _pool->release(this, false);
        }

        static std::shared_ptr<ITask> create(F &&f) {
            return _pool->acquirePtr(std::forward<F>(f));
        }

    private:
        F func_;
        static ObjPool<TaskImpl<F> > *_pool;
    };

    template<typename F>
    ObjPool<TaskImpl<F> > *TaskImpl<F>::_pool = new ObjPool<TaskImpl<F> >();

    typedef std::shared_ptr<ITask> TaskPtr;

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

        template<typename F>
        void execute(F &&run, int threadHashCode = 0) {
            int threadIndex = threadHashCode % (int) _threads.size();
            //   auto funcTask = std::make_shared<TaskImpl<F> >(run);
            auto it = TaskImpl<F>::create(std::forward<F>(run));
            _threads[threadIndex]->execute(it);
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
