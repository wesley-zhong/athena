#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#include <functional>
#include <map>
#include <iostream>
#include <google/protobuf/message.h>
#include "Singleton.h"


#define REGISTER_MSG_ID_FUN(MSGID, FUNCTION) \
Dispatcher::Instance()->registerMsgHandler(100, std::function(FUNCTION))

struct MsgFunction {
    google::protobuf::Message *param;
    std::function<void(int64_t, void *)> function;
};

class Dispatcher : public Singleton<Dispatcher> {

public:
    Dispatcher() {};

    ~Dispatcher() {};

    template<typename T>
    void registerMsgHandler(int msgId, std::function<void(int64_t, T *)> msgFuc);

//  template <typename T>
//  void  registerMsgHandlers(int msgId, std::function<void(int, std::shared_ptr<T>)> msgFuc);

    void callFunction(MsgFunction *msgFunction, int64_t pid, void *param_);

    void processMsg(int msgId, int64_t playerId, const void *body, int len);
    // template <typename T>
    // void callFunction(int msgId, std::shared_ptr<T> param_);

private:
    std::map<int, MsgFunction *> msgMap;
    // std::map<int, std::function<void(int, std::shared_ptr<void> )>> msgSMap;
};

template<typename T>
void Dispatcher::registerMsgHandler(int msgId, std::function<void(int64_t, T*)> msgFuc) {
    MsgFunction *msgFunction = new MsgFunction();
    msgFunction->function = [msgFuc](int64_t p1, void *p2) {
        msgFuc(p1, (T *) p2);
    };
    msgFunction->param = new T();
    msgMap[msgId] = msgFunction;
}
// template <typename T>
// void Dispatcher::registerMsgHandlers(int msgId, std::function<void(int, std::shared_ptr<T>)> msgFuc)
// {
//     msgMap[msgId] = [msgId, msgFuc](int p1, std::shared_ptr<void> p2)
//   {
//     msgFuc(msgId, (std::shared_ptr<T>)p2);
//   };
// }


void Dispatcher::callFunction(MsgFunction *msgFunction, int64_t playerId, void* param_) {
    msgFunction->function(playerId, (void *) param_);
}

// template <typename T>
// void Dispatcher::callFunction(int msgId, std::shared_ptr<T> param_)
// {
//   auto func = msgSMap[msgId];
//   if (func != nullptr)
//   {
//     func(msgId, (std::shared_ptr<void>)param_);
//   }
// }

void Dispatcher::processMsg(int msgId, int64_t playerId, const void *body, int len) {
    auto func = msgMap[msgId];
    if (func == nullptr) {
        INFO_LOG("msg id ={} not found", msgId);
        return;
    }
    func->param->ParseFromArray(body, len);
    callFunction(func,playerId, func->param);
}

#endif