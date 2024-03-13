#include<iostream>
#include "INetEvent.h"
#include "network/NetPacket.h"
#include "network/NetConnect.h"
#include "common/Dispatcher.hpp"


void INetEvent::onAccept(NetConnect *conn)
{
    std::cout<<"on accept" <<std::endl;
}
void INetEvent::onClose(NetConnect *conn)
{
    std::cout<<"on closed" <<std::endl;
}
void INetEvent::onMsg(NetConnect *conn, int msgtype, NetPacket *pack)
{
    std::cout<<"on onMsg:"<<pack->getBodyData()<< " bodyLen :" << pack->getBodySize() <<std::endl;
   // for(int i = 0 ; i < 100; i ++){
    NetPacket* netPacket = new NetPacket();
    netPacket->pushString("hello");
    conn->sendMsg(122 , netPacket);

    Dispatcher::dispatcher(1);
  //  }
}