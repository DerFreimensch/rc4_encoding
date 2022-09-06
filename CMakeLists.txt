cmake_minimum_required(VERSION 3.23)
project(rc4)

set(CMAKE_CXX_STANDARD 20)

add_executable(rc4 main.cpp rc4.cpp rc4.h)
