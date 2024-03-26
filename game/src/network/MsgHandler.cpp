#include "MsgHandler.h"
#include "common/XLog.h"
#include "GameRole.h"


void MsgHandler:: onLogin(int playerId, GameRole* gameRole){
    INFO_LOG("HELLO playdiId ={} roleId = {}",playerId, gameRole->getPid());
}