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
#include "common/ObjPool.h"

using namespace hv;

int main(int argc, char **argv) {
    xLogInitLog(LogLevel::LL_INFO, "../logs/game.log");
    //    AthenaTcpServer athenaTcpServer;
    //    athenaTcpServer.start(30001);


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
    std::shared_ptr<InnerHead> pInnherHead2 = std::make_shared<InnerHead>();
    bool ret = pInnherHead2->ParseFromString(pServer);
    // std::cout<<"------ "<<pInnherHead2->id() <<std::endl;
    INFO_LOG("------{}", pInnherHead2->id());
    //
    //Dispatcher::Instance()->registerMsgHandler(100, std::function(MsgHandler::onLogin));
    REGISTER_MSG_ID_FUN(100, MsgHandler::onSomeMsg);
    Dispatcher::Instance()->processMsg(100, 8889, pServer.c_str(), pServer.length());

    Thread::ThreadPool *threadPool = new AthenaThreadPool();
    threadPool->create(2);

    int i = 1;
    i++;
    threadPool->execute([i]() {
        INFO_LOG("LLLLLL2={}", i);
    }, 2);

    ObjPool<GameRole> *ptrGameRolePoolPtr = new ObjPool<GameRole>(1, 2);
    {
        auto ptr = ptrGameRolePoolPtr->acquire(100);
        INFO_LOG("LLLL3444 pid ={}", ptr->getPid());
    }


    threadPool->execute([] {
    INFO_LOG("LLLLLL1={}", 1);
}, 1);

    // Dispatcher::Instance()->registerMsgHandler<InnerHead>(101, std::function(MsgHandler::onSomeMsg));
    //    GameRole *role = new GameRole();
    //    role->setPid(1000);
    // Dispatcher::Instance()->callFunction(100, 10000000001,role);
    //  Dispatcher::Instance()->callFunction(101, pInnherHead2.get());


    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}
