//
// Created by zhongweiqi on 2025/10/20.
//

#include "AthenaTcpClient.h"
#include "XLog.h"
#include "hv/htime.h"

int AthenaTcpClient::connect(std::string ip, int port) {
    int connfd = cli->createsocket(port, ip.c_str());
    if (connfd < 0) {
        return -1;
    }

    cli->onConnection = std::bind(&AthenaTcpClient::onConnection, this, std::placeholders::_1);
    cli->onMessage = std::bind(&AthenaTcpClient::onMessage, this, std::placeholders::_1, std::placeholders::_2);
    reconn_setting_t *reconn = new reconn_setting_t();
    reconn_setting_init(reconn);
    reconn->min_delay = 1000;
    reconn->max_delay = 10000;
    reconn->delay_policy = 2;
    cli->setReconnect(reconn);
    cli->start();
    return 0;
}

void AthenaTcpClient::onConnection(const hv::SocketChannelPtr &channel) {
    std::string peeraddr = channel->peeraddr();
    if (channel->isConnected()) {
        INFO_LOG("connected to {}! connfd={}", peeraddr.c_str(), channel->fd());
        channels.push_back(channel);
        // send(time) every 3s
        hv::setInterval(3000, [channel](hv::TimerID timerID) {
            if (channel->isConnected()) {
                if (channel->isWriteComplete()) {
                    char str[DATETIME_FMT_BUFLEN] = {0};
                    datetime_t dt = datetime_now();
                    datetime_fmt(&dt, str);
                    channel->write(str);
                }
            } else {
                hv::killTimer(timerID);
            }
        });
    } else {
        INFO_LOG("disconnected to {}  connfd={}\n", peeraddr.c_str(), channel->fd());
    }
    if (cli->isReconnect()) {
        INFO_LOG("reconnect cnt= {}, delay={}", cli->reconn_setting->cur_retry_cnt, cli->reconn_setting->cur_delay);
    }
}

void AthenaTcpClient::onMessage(const hv::SocketChannelPtr &channel, hv::Buffer *buf) {
    INFO_LOG("< {}{}\n", (int)buf->size(), (char*)buf->data());
}
