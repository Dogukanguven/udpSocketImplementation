cmake_minimum_required(VERSION 3.10.2)
project(udpSocketImplementation)

set(CMAKE_CXX_STANDARD 17)

add_executable(client client.cpp)

add_executable(server server.cpp)