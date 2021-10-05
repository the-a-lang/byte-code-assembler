//
// Created by a404m on 9/24/21.
//

#ifndef BYTE_CODE_ASSEMBLER_ITEM_H
#define BYTE_CODE_ASSEMBLER_ITEM_H

#include <string>
#include <variant>

namespace BCA {
    struct Item {
    public:
        enum Type{
            ID,
            KEYWORD
        };

        std::string str;
        Type type;

        Item(std::string,Type);
    };
}//namespace BCA


#endif //BYTE_CODE_ASSEMBLER_ITEM_H
