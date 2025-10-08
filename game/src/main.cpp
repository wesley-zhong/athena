#include <chrono>
#include "sol/sol.hpp"
#include <iostream>

#include "common/RingBuffer.hpp"
#include "common/XLog.h"
#include "network/Dispatcher.h"
#include "network/AthenaTcpServer.h"
#include "MsgHandler.h"
#include "GameRole.h"
#include "ProtoInner.pb.h"
#include "hv/TcpServer.h"
#ifdef WIN32
#pragma comment(lib,"ws2_32.lib")
#endif // WINDIWS

using namespace hv;
int main(int argc, char **argv)
{
    xLogInitLog(LogLevel::LL_INFO, "../logs/game.log");
    AthenaTcpServer athenaTcpServer;
    athenaTcpServer.start(30001);
//     EventLoop::Instance()->init();
//     INetEvent* eve = new INetEvent();
//     NetServer* netServer = new  NetServer(EventLoop::Instance(), eve);
//     netServer->listen("127.0.0.1", 3001);
//     INFO_LOG("ready start  server :3001");
//
//     return EventLoop::Instance()->run();





//     RingBuffer<int *> *pRingBuf = new RingBuffer<int *>(3);
//     int i1 = 1;
//     int i2 = 2;
//     int i3 = 3;
//     int i4 = 4;     int **arrya = new int *[4];
//     pRingBuf->push(arrya, 4);
//     int* op = pRingBuf->pop();
//     if (op == nullptr) {
//         INFO_LOG("not found element");
//     }
//     pRingBuf->push(&i1);
//     pRingBuf->push(&i2);
//     pRingBuf->push(&i3);
//     for (int i = 0; i < 1000; ++i)
//     {
//         int *point = pRingBuf->pop();
//         pRingBuf->push(&i4);
//     }
//
//    // pRingBuf->push(&i4);
//
//     std::shared_ptr<InnerHead>pInnherHead = std::make_shared<InnerHead>();
//     pInnherHead->set_id(111);
//     std::string pServer = pInnherHead->SerializeAsString();
//     std::shared_ptr<InnerHead>pInnherHead2 = std::make_shared<InnerHead>();
//     bool ret = pInnherHead2->ParseFromString(pServer);
//    // std::cout<<"------ "<<pInnherHead2->id() <<std::endl;
//     INFO_LOG("------", pInnherHead2->id());
//
//    Dispatcher::Instance()->registerMsgHandler(100, std::function(MsgHandler::onLogin));
//    Dispatcher::Instance()->registerMsgHandler(101, std::function(MsgHandler::onSomeMsg));
//    GameRole *role = new GameRole();
//    role->setPid(1000);
//    Dispatcher::Instance()->callFunction(100, role);
//    Dispatcher::Instance()->callFunction(101, pInnherHead2.get());



    return 0;
}
