#include <iostream>
#include "INetEvent.h"
#include "network/NetPacket.h"
#include "network/NetConnect.h"
#include "common/Dispatcher.hpp"
#include "GameRole.hpp"
#include "common/XLog.h"

void INetEvent::onAccept(NetConnect *conn)
{
    GameRole *gameRole = new GameRole();
    gameRole->setPid(9999);
    gameRole->setNetConn(conn);
    INFO_LOG("on accept {}", conn->remoteIP());
    conn->setUserdata(gameRole);
}
void INetEvent::onClose(NetConnect *conn)
{
    GameRole *gameRole = (GameRole *)conn->getUserdata();
    if (gameRole != nullptr)
    {
        delete gameRole;
    }
    INFO_LOG("on closed {}", conn->remoteIP());
}
void INetEvent::onMsg(NetConnect *conn, int msgtype, NetPacket *pack)
{
    GameRole *gameRole = (GameRole *)conn->getUserdata();
    INFO_LOG("on onMsg {}  bodyLen={}", pack->getBodyData(), pack->getBodySize());
    // for(int i = 0 ; i < 100; i ++){
    NetPacket *netPacket = new NetPacket();
    netPacket->pushString("hello");
    conn->sendMsg(122, netPacket);

    // Dispatcher::dispatcher(1);
    //  }
}