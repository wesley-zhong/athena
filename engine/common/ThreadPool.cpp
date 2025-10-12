#include "ThreadPool.h"
#include <thread>
#include <utility>
#include<memory.h>

using namespace Thread;

Task::~Task() {

}

CThread::CThread() :
        _thread(CThread::thread_func, this) {
    _thread.detach();
}

CThread::~CThread() {

}

void CThread::thread_func(CThread *t) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    t->onStart();
    while (t->_isrun) {
        TaskPtr task = t->popWaitTask();
        if (task == nullptr) {
            t->run(task);
            continue;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    t->onEnd();
}

void CThread::stop() {
    _isrun = false;
    _thread.join();
}

void CThread::run(TaskPtr task) {
    task->process();
}

void CThread::executeTask(TaskPtr task) {
    _waitTasks.push(task);
}

TaskPtr CThread::popWaitTask() {
    TaskPtr task;
    if (!_waitTasks.tryPop(task))
        return nullptr;
    return task;
}

ThreadPool::ThreadPool() = default;


ThreadPool::~ThreadPool() {
    exit();
}

void ThreadPool::create(int count) {
    for (int i = 0; i < count; ++i) {
        CThread *t = createThread();
        if (t) {
            _threads.push_back(t);
        }
    }
}

void ThreadPool::exit() {
    for (CThread *t: _threads) {
        t->stop();
        deleteThread(t);
    }
    _threads.clear();
}

void ThreadPool::addTask(TaskPtr task, int threadHashCode) {
    int threadIndex = threadHashCode % (int)_threads.size();
    _threads[threadIndex]->executeTask(std::move(task));
}


void ThreadPool::update() {
    TaskPtr task;
    if (!_completeTasks.tryPop(task))
        return;

    task->complete();
    completeTask(task);
}