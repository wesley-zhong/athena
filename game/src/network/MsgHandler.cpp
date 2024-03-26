#include "MsgHandler.h"
#include "common/XLog.h"
#include "GameRole.h"
#include "ProtoInner.pb.h"


void MsgHandler::onLogin(int playerId, GameRole* gameRole){
    INFO_LOG("HELLO playdiId ={} roleId = {}",playerId, gameRole->getPid());
}

void MsgHandler::onSomeMsg(int playerId, InnerHead* InnerHead ){
    INFO_LOG("HELLO playdiId ={} innherHeaderId = {}",playerId, InnerHead->id());
}