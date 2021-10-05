//
// Created by a404m on 10/5/21.
//

#ifndef BYTE_CODE_ASSEMBLER_LEXED_H
#define BYTE_CODE_ASSEMBLER_LEXED_H

#include <string>

namespace BCA {
    struct Lexed {
    public:
        enum Token{
            NONE = 0,
            ID,
            NUMBER,
            STRING,
            KEYWORD,
            SYMBOL
        };
        std::string str;
        Token token;

        Lexed(std::string,Token);

        void clear();
    };
}


#endif //BYTE_CODE_ASSEMBLER_LEXED_H
