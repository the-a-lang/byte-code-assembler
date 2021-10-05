//
// Created by a404m on 9/23/21.
//

#include <iostream>
#include <chrono>
#include "byte-code-assembler/parser/Parser.h"

using namespace BCA;

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    auto lexer = Lexer{
            R"(
section header
    main_fun main
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
    auto end = std::chrono::high_resolution_clock::now();
    auto diff = end - begin;
    std::cout << std::chrono::duration<long double, std::milli>(diff).count() << "ms" << std::endl;
    return 0;
}