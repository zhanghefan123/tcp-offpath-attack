//
// Created by zhf on 2024/11/7.
//

#ifndef TCP_OFF_PATH_COMMON_H
#define TCP_OFF_PATH_COMMON_H

#include <tins/tins.h>

typedef std::chrono::high_resolution_clock::time_point Clock;
typedef Tins::HWAddress<6> MACAddress;

class CommandArgs {
public:
    char *INTERFACE_NAME{};
    char *VICTIM_IP{};
    char *SERVER_IP{};
    int SERVER_PORT{};
    MACAddress VICTIM_MAC;
    MACAddress SERVER_MAC;
};

class GlobalArgs {
public:
    CommandArgs commandArgs;
    Tins::PacketSender packetSender;
    GlobalArgs();
    void SetCommandArgs(CommandArgs commandArgs);
    void SetPacketSender(Tins::PacketSender& packetSender);
};

extern GlobalArgs globalArgs;

#endif //TCP_OFF_PATH_COMMON_H
