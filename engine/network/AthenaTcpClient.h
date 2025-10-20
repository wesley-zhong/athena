//
// Created by zhongweiqi on 2025/10/20.
//

#ifndef ATHENA_ATHENATCPCLIENT_H
#define ATHENA_ATHENATCPCLIENT_H
#include "hv/TcpClient.h"

enum SeverType {
    E_LOGIN_SRV,
    E_GATEWAY_SRV,
    E_GAME_SRV,
};

class AthenaTcpClient {
public:
    AthenaTcpClient() {
        cli = std::make_shared<hv::TcpClient>();
    }

    int connect(std::string ip, int port);

    void onConnection(const hv::SocketChannelPtr &channel);

    void onMessage(const hv::SocketChannelPtr &channel, hv::Buffer *buf);

private:
    bool isConnected;
    std::shared_ptr<hv::TcpClient> cli;
     std::vector<hv::SocketChannelPtr>  channels;
};

#endif //ATHENA_ATHENATCPCLIENT_H
