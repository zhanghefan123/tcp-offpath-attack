cmake_minimum_required(VERSION 3.22)
project(tcp_off_path)

set(CMAKE_CXX_STANDARD 11)

add_executable(tcp_off_path
        src/main.cpp
        src/sniffer/sniffer.cpp
        src/synchronizer/synchronizer.cpp
        src/common/common.cpp
        src/route/route.cpp)

set(HEADERS_DIR
        /usr/local/include
        src/headers)

# CLion IDE will find symbols from <linux/*>
target_include_directories("tcp_off_path" PRIVATE ${HEADERS_DIR}) # clion -> tools -> resync with remote hosts
target_link_libraries("tcp_off_path" PRIVATE tins)

