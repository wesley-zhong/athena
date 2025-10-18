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
#include "thread/AthenaThreadPool.h"
#include "common/ObjectPool.hpp"
#include "db/Dal.hpp"

using namespace hv;

int main(int argc, char **argv) {
    xLogInitLog(LogLevel::LL_INFO, "../logs/game.log");
    //    AthenaTcpServer athenaTcpServer;
    //    athenaTcpServer.start(30001);

    std::string ip = "172.18.2.101";
    Dal::Cache::init(ip, 6379,"","","");

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
    std::shared_ptr<InnerHead> pInnherHead = std::make_shared<InnerHead>();
    pInnherHead->set_id(14441);
    std::string pServer = pInnherHead->SerializeAsString();
    // std::shared_ptr<InnerHead> pInnherHead2 = std::make_shared<InnerHead>();
    // bool ret = pInnherHead2->ParseFromString(pServer);
    // // std::cout<<"------ "<<pInnherHead2->id() <<std::endl;
    // INFO_LOG("------{}", pInnherHead2->id());

    // REGISTER_MSG_ID_FUN(100, MsgHandler::onSomeMsg);
    // Dispatcher::Instance()->processMsg(100, 8889, pServer.c_str(), pServer.length());

    REGISTER_MSG_ID_FUN(100, MsgHandler::onSomeMsg);
    Thread::ThreadPool *threadPool = new AthenaThreadPool();
    threadPool->create(2);

    int msgId = 100;
    int playerId = 999;
    threadPool->execute([msgId, playerId, pServer]() {
        Dispatcher::Instance()->processMsg(msgId, playerId, pServer.c_str(), pServer.length());
    }, 2);

    int i = 1;
    i++;
    threadPool->execute([i]() {
        INFO_LOG("thread test 2={}", i);
    }, 2);

    threadPool->execute([i]() {
        INFO_LOG("thread test 2={}", i);
    }, 2);


    // ObjPool<GameRole> *ptrGameRolePoolPtr = new ObjPool<GameRole>(1, 2);
    // {
    //     auto ptr = ptrGameRolePoolPtr->acquire(100);
    //     INFO_LOG("pool obj GameRole test  pid ={}", ptr->getPid());
    // }
    INFO_LOG("==========================  wait release");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    threadPool->execute([]() {
        INFO_LOG("thread test   obj=3");
    }, 2);


    INFO_LOG("========================== should be hit");
    int x = 100;
    threadPool->execute([x]() {
        INFO_LOG("thread test x=2={}", x);
    }, 2);

    threadPool->execute([] {
        INFO_LOG(" thread test 1={}", 1);
    }, 1);

   std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}
