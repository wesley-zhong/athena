#ifndef NET_EVENT_H
#define NET_EVENT_H

class NetConnect;
class NetPacket;

class NetEvent
{
public:
	NetEvent();
	virtual ~NetEvent();

	virtual NetConnect * createConnect();
	virtual void destroyConnect(NetConnect * conn);

	virtual void onAccept(NetConnect * conn)=0;
	virtual void onConnect(NetConnect * conn, int argv){};
	virtual void onClose(NetConnect * conn)=0;
	virtual void onMsg(NetConnect * conn, int msgtype, NetPacket * pack)=0;

};

#endif