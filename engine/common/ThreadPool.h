#pragma once

#include <functional>
#include <vector>
#include <thread>
#include "TQueue.h"
#include "XLog.h"

using RunFunction = void(*)();

namespace Thread {
    class ITask {
    public:
        virtual ~ITask();

        virtual void run() = 0;

        virtual void complete() = 0;
    };

    template<typename F>
    class TaskImpl : public ITask {
    public:
        explicit TaskImpl(F &&f) : func_(std::forward<F>(f)) {
        }
        explicit TaskImpl(F &f) : func_(std::forward<F>(f)) {
        }


        void run() override { func_(); }

        void complete() override {
        }
        ~TaskImpl() {}

    private:
        F func_;
    };

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

        void executeTask(TaskPtr task, int threadHashCode = 0);

        template<typename F>
        void execute(F &&run, int threadHashCode = 0) {
            int threadIndex = threadHashCode % (int) _threads.size();
            auto funcTask = std::make_shared<TaskImpl<F> >(run);
            _threads[threadIndex]->execute(funcTask);
        }

        void update();

    protected:
        virtual Worker *createThread() = 0;

        virtual void deleteThread(Worker *t) = 0;

        virtual void completeTask(TaskPtr task) = 0;

    private:
        std::vector<Worker *> _threads;
        TQueue<TaskPtr> _completeTasks;
    };
}
