#ifndef DISPATCHER_H_
#define DISPATCHER_H_
#include <functional>
#include <map>
#include "Singleton.h"
#include <iostream>

class Dispatcher : public Singleton<Dispatcher>
{

public:
  Dispatcher(){};
  ~Dispatcher(){};
  template <typename T>
  void registerMsgHandler(int msgId, std::function<void(int, T *)> msgFuc);
  //template <typename T>
  //void Dispatcher::registerMsgHandlers(int msgId, std::function<void(int, std::shared_ptr<T>)> msgFuc);
  template <typename T>
  void callFunction(int msgId, T *param_);
 // template <typename T>
 // void callFunction(int msgId, std::shared_ptr<T> param_);

private:
  std::map<int, std::function<void(int, void *)>> msgMap;
 // std::map<int, std::function<void(int, std::shared_ptr<void> )>> msgSMap;
};

template <typename T>
void Dispatcher::registerMsgHandler(int msgId, std::function<void(int, T *)> msgFuc)
{
  msgMap[msgId] = [msgId, msgFuc](int p1, void *p2)
  {
    msgFuc(msgId, (T *)p2);
  };
}
// template <typename T>
// void Dispatcher::registerMsgHandlers(int msgId, std::function<void(int, std::shared_ptr<T>)> msgFuc)
// {
//   msgSMap[msgId] = [msgId, msgFuc](int p1, std::shared_ptr<void> p2)
//   {
//     msgFuc(msgId, (std::shared_ptr<T>)p2);
//   };
// }

template <typename T>
void Dispatcher::callFunction(int msgId, T *param_)
{
  auto func = msgMap[msgId];
  if (func != nullptr)
  {
    func(msgId, (void *)param_);
  }
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

#endif