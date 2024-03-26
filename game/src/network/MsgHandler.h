#ifndef MSGHANDLER_H_
#define MSGHANDLER_H_
#include "common/Singleton.h"
class GameRole;
class MsgHandler :public Singleton<MsgHandler>
{
private:
    /* data */
public:
    MsgHandler(/* args */){};
    ~MsgHandler(){};
    static void  onLogin(int playerId, GameRole* GameRole);
};

#endif