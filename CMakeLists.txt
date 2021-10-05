cmake_minimum_required(VERSION 3.20)
project(byte_code_assembler)

#set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-Ofast")
#set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

#include_directories(.)

add_executable(byte_code_assembler
        main.cpp byte-code-assembler/additional/functions.cpp byte-code-assembler/additional/functions.h byte-code-assembler/command/Command.cpp byte-code-assembler/command/Command.h byte-code-assembler/command/item/Item.cpp byte-code-assembler/command/item/Item.h byte-code-assembler/lexer/Lexer.cpp byte-code-assembler/lexer/Lexer.h byte-code-assembler/lexer/lexed/Lexed.cpp byte-code-assembler/lexer/lexed/Lexed.h byte-code-assembler/parser/Parser.cpp byte-code-assembler/parser/Parser.h byte-code-assembler/data/Data.cpp byte-code-assembler/data/Data.h byte-code-assembler/byte-code-generator/ByteCodeGenerator.cpp byte-code-assembler/byte-code-generator/ByteCodeGenerator.h)
