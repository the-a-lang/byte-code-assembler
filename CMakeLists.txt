cmake_minimum_required(VERSION 3.20)
project(byte_code_assembler)

#set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-Ofast")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

#include_directories(.)

add_executable(byte_code_assembler
        main.cpp)
