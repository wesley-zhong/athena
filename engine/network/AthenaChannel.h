//
// Created by zhongweiqi on 2025/10/20.
//

#ifndef ATHENA_ATHENACHANNEL_H
#define ATHENA_ATHENACHANNEL_H
#include "hv/Channel.h"
#include "google/protobuf/message.h"

class AthenaChannel {
public:
    AthenaChannel(const hv::ChannelPtr &hvChannel) {
        _hvChannel = hvChannel;
    }

    void send(int msgId, google::protobuf::Message& message);

private:
    const hv::ChannelPtr _hvChannel;
};

#endif //ATHENA_ATHENACHANNEL_H
