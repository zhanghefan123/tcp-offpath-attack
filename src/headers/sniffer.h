//
// Created by zhf on 2024/11/7.
//

#ifndef TCP_OFF_PATH_SNIFFER_H
#define TCP_OFF_PATH_SNIFFER_H
#include <tins/tins.h>
#include <iostream>
#include <atomic>

// 监听计数器
extern std::atomic<unsigned int> sniff_counter;

// 创建配置
Tins::SnifferConfiguration create_sniffer_config(const std::string& local_addr);

// 主程序
void sniff_main(const std::string& local_addr, const std::string& listen_interface_name);

#endif //TCP_OFF_PATH_SNIFFER_H
