//
// Created by a404m on 9/23/21.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include "byte-code-assembler/byte-code-generator/ByteCodeGenerator.h"

using namespace BCA;

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    auto lexer = Lexer{
R"(
section header
    global main
section data
    one int 1
    two int 2
section code
    main:
    decl a,int,one
    mov a,two ;this is a comment
    RET
)"};
    auto parser = Parser{lexer};
    auto bytecode = ByteCodeGenerator(parser);
    auto end = std::chrono::high_resolution_clock::now();
    auto diff = end - begin;
    std::cout << std::chrono::duration<long double, std::milli>(diff).count() << "ms" << std::endl;
    std::ofstream file{"out.abc"};
    file << bytecode.holder;
    return 0;
}