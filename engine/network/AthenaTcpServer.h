//
// Created by Wesly Zhong on 2025/10/6.
//

#ifndef ATHENA_ATHENATCPSERVER_H
#define ATHENA_ATHENATCPSERVER_H
#include <memory>
#include"hv/TcpServer.h"

class AthenaTcpServer {
public:
    int start(int port, int threadNum);

    ~AthenaTcpServer();

private:
    std::shared_ptr<hv::TcpServer> tcpServer;
};


#endif //ATHENA_ATHENATCPSERVER_H
