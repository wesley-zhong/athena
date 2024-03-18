#include <chrono>
#include "sol/sol.hpp"
#include <iostream>
#include "network/TcpServer.h"
#include "INetEvent.h"
#include "common/EventLoop.h"
#include "network/NetServer.h"
#include "common/RingBuffer.hpp"
#include "common/XLog.h"

int main(int argc, char **argv)
{
    xLogInitLog(LogLevel::LL_INFO);
    EventLoop::Instance()->init();
    INetEvent* eve = new INetEvent();
    NetServer* netServer = new  NetServer(EventLoop::Instance(), eve);
    netServer->listen("127.0.0.1", 3001);
    std::cout<<"ready start  server"<<std::endl;

    return EventLoop::Instance()->run();

    // RingBuffer<int *> *pRingBuf = new RingBuffer<int *>(3);
    // int i1 = 1;
    // int i2 = 2;
    // int i3 = 3;
    // int i4 = 4;
    // int **arrya = new int *[4];
    // pRingBuf->push(arrya, 4);
    // pRingBuf->pop();
    // pRingBuf->push(&i1);
    // pRingBuf->push(&i2);
    // pRingBuf->push(&i3);
    // for (int i = 0; i < 1000; ++i)
    // {
    //     int *point = pRingBuf->pop();
    //     pRingBuf->push(&i4);
    // }

    // pRingBuf->push(&i4);
}
