//
// Created by zhf on 2024/11/7.
//
#include "common.h"

#include <utility>

GlobalArgs::GlobalArgs() = default;

void GlobalArgs::SetCommandArgs(CommandArgs commandArgsTmp){
    this->commandArgs = commandArgsTmp;
}

void GlobalArgs::SetPacketSender(Tins::PacketSender& packetSenderTmp){
    this->packetSender = std::move(packetSenderTmp);
}

// CommandArgs commandArgs, Tins::PacketSender packetSender