#include<iostream>
#include "INetEvent.h"
#include "network/NetPacket.h"


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
}