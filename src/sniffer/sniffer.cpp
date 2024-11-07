//
// Created by zhf on 2024/11/7.
//

#include "sniffer.h"

std::atomic<unsigned int> sniff_counter;

Tins::SnifferConfiguration create_sniffer_config(const std::string& local_addr) {
    char filter [100];
    Tins::SnifferConfiguration sniffer_config;
    sprintf(filter, "ip and tcp[tcpflags] == tcp-ack and dst %s", local_addr.c_str());
    sniffer_config.set_promisc_mode(false);
    sniffer_config.set_filter(filter);
    return sniffer_config;
}

bool found_new_packet(Tins::PDU &some_pdu) {
    sniff_counter++;
    return true;
}

void sniff_main(const std::string& local_addr, const std::string& listen_interface_name){
    // 日志输出
    std::cout << "start sniffer" << std::endl;

    // 创建配置
    auto sniffer_config = create_sniffer_config(local_addr);

    // 创建 sniffer
    Tins::Sniffer sniffer(listen_interface_name, sniffer_config);

    // 循环进行监听
    sniffer.sniff_loop(found_new_packet);
}

