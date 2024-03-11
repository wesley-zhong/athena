#include "network/NetEvent.h"
class INetEvent : public NetEvent
{
public:
    INetEvent()
    {
    }
     void onAccept(NetConnect *conn) ;
     void onClose(NetConnect *conn) ;
     void onMsg(NetConnect *conn, int msgtype, NetPacket *pack);
};