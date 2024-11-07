#include <iostream>
#include "common.h"

GlobalArgs globalArgs = GlobalArgs();

void resolve_command_args(int argc, char** argv);

int main(int argc, char** argv) {
    // 解析命令行参数
    resolve_command_args(argc, argv);

    return 0;
}

void resolve_command_args(int argc, char** argv){
    if (argc != 5) {
        std::cout << "Error Parameters (1. interface name | 2. victim ip | 3. server ip | 4. server port )" << std::endl;
        exit(-1);
    }
    char* interface_name = argv[1];
    Tins::PacketSender sender = Tins::PacketSender(interface_name);
    CommandArgs commandArgs = CommandArgs();
    commandArgs.INTERFACE_NAME = argv[1];
    commandArgs.VICTIM_IP = argv[2];
    commandArgs.SERVER_IP = argv[3];
    commandArgs.SERVER_PORT = atoi(argv[4]);
    commandArgs.VICTIM_MAC = Tins::Utils::resolve_hwaddr(commandArgs.VICTIM_IP, sender);
    commandArgs.SERVER_MAC = Tins::Utils::resolve_hwaddr(commandArgs.SERVER_IP, sender);
    globalArgs.SetCommandArgs(commandArgs);
    globalArgs.SetPacketSender(sender);

    printf("VICTIM_IP: %s | SERVER_IP: %s | SERVER_PORT: %d\n", commandArgs.VICTIM_IP, commandArgs.SERVER_IP, commandArgs.SERVER_PORT);
    printf("VICTIM_MAC: %s | SERVER_MAC: %s \n", commandArgs.VICTIM_MAC.to_string().c_str(), commandArgs.SERVER_MAC.to_string().c_str());
}