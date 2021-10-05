//
// Created by a404m on 9/24/21.
//

#ifndef BYTE_CODE_ASSEMBLER_COMMAND_H
#define BYTE_CODE_ASSEMBLER_COMMAND_H

#include "item/Item.h"
#include <vector>
#include <stdexcept>

namespace BCA {
    struct Command {
    public:
        enum Token {
            NO_COMMAND = 0,
            DECL,
            MOV,
            ADD,
            SUB,
            MUL,
            DIV,
            CALL,
            RET,
        };
        Token token;
        std::vector<Item> operands;

        explicit Command(const std::string &,std::vector<Item>  = {});

        static Token toToken(const std::string&);
    };
}//namespace BCA


#endif //BYTE_CODE_ASSEMBLER_COMMAND_H
