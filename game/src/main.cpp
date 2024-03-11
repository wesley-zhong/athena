#include <chrono>
#include "sol/sol.hpp"
#include <iostream>
#include "network/TcpServer.h"
#include "INetEvent.h"
#include "common/EventLoop.h"
#include "network/NetServer.h"


int main(int argc, char **argv)
{
    EventLoop::Instance()->init();
    INetEvent* eve = new INetEvent();
    NetServer* netServer = new  NetServer(EventLoop::Instance(), eve);
    netServer->listen("127.0.0.1", 3001);
    std::cout<<"ready start  server"<<std::endl;

    return EventLoop::Instance()->run();
}
