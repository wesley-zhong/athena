//
// Created by Wesly Zhong on 2025/10/6.
//

#include "AthenaTcpServer.h"
#include"hv/TcpServer.h"

#include"XLog.h"
#include "hv/herr.h"

using namespace  hv;

int AthenaTcpServer::start(int port) {
    TcpServer srv;

    int listenfd = srv.createsocket(port);
    if (listenfd < 0) {
        return -1;
    }

    // 配置拆包设置
//    unpack_setting_t setting;
//
//    // 设置为长度字段拆包模式
//    setting.mode = UNPACK_BY_LENGTH_FIELD;
//    setting.package_max_length = 4 * 1024; // 最大包长度14k
//    setting.length_field_offset = 0; // 长度字段在位置0
//    setting.length_field_bytes = 4;// 长度字段占4字节
//    setting.body_offset =4;
//    setting.length_adjustment = 0;     // 不调整
//    setting.length_field_coding =ENCODE_BY_BIG_ENDIAN;
//    srv.setUnpack(&setting);

  //  srv.setUnpack(HEADER_LEN_UNPACK)
    INFO_LOG("server listen on port {}, listenfd={} ", port, listenfd);
    srv.onConnection = [](const SocketChannelPtr& channel) {
        std::string peeraddr = channel->peeraddr();
        if (channel->isConnected()) {
            channel->setKeepaliveTimeout(9000);
            INFO_LOG("{} connected! connfd={}", peeraddr.c_str(), channel->fd());
        } else {
            INFO_LOG("{} disconnected! connfd={} reason={}", peeraddr.c_str(), channel->fd(),  hv_strerror( channel->error()));
        }
    };

    srv.onMessage = [](const SocketChannelPtr& channel, Buffer* buf) {
        // echo

        //hv_ntoh16();
        channel->write(buf);
    };

    srv.setThreadNum(4);
    srv.setLoadBalance(LB_LeastConnections);
    srv.start();

    // press Enter to stop
    while (getchar() != '\n');
    return 0;
}