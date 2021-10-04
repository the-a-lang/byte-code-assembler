//
// Created by a404m on 9/24/21.
//

#ifndef BYTE_CODE_ASSEMBLER_COMMAND_H
#define BYTE_CODE_ASSEMBLER_COMMAND_H

#include "item/Item.h"
#include <vector>

namespace BCA {
    class Command {
    public:
        enum Token {
            DECL = 0,
            MOV,
            ADD,
            SUB,
            MUL,
            DIV,
            CALL,
            RET,
            PUSH,
            POP
        };
        Token token;
        std::vector<Item> operands;

        explicit Command(const std::string&,const std::initializer_list<Item>& = {});

    private:
        static Token toToken(const std::string&);
    };
}//namespace BCA


#endif //BYTE_CODE_ASSEMBLER_COMMAND_H
