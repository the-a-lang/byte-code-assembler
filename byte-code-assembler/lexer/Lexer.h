//
// Created by a404m on 10/4/21.
//

#ifndef BYTE_CODE_ASSEMBLER_LEXER_H
#define BYTE_CODE_ASSEMBLER_LEXER_H

#include "../command/Command.h"
#include "lexed/Lexed.h"
#include "../additional/functions.h"

namespace BCA {
    class Lexer {
        friend class Parser;
    private:
        std::string str;
        std::vector<std::vector<Lexed>> holder;
    public:
        explicit Lexer(std::string);

    private:
        static void push_clear(std::vector<Lexed>&,Lexed&);
        static void push_clear_ifn_emtpy(std::vector<Lexed>&,Lexed&);
    };
}//namespace BCA

#endif //BYTE_CODE_ASSEMBLER_LEXER_H
