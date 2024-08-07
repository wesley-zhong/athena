#ifndef GAME_ROLE_HPP_
#define GAME_ROLE_HPP_
#include "network/NetConnect.h"
class GameRole
{
private:
   uint32_t  pid;
   NetConnect * netConn;
 
    /* data */
public:
    GameRole(/* args */){};
    ~GameRole(){};
    uint32_t  getPid(){
        return pid;
    }
    NetConnect* getNetConn(){
        return netConn;
    }
    void setPid(uint32_t pid){
        this->pid = pid;
    }
    void setNetConn(NetConnect* netConn){
        this->netConn = netConn;
    }
};

#endif