cmake_minimum_required(VERSION 3.20)
project(byte_code_assembler)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(byte_code_assembler
        main.cpp)
