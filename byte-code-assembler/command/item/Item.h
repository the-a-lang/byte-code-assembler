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
        using String = std::string;
        using Float = long double;
        using Int = long long int;
        using HolderType = std::variant<String, Float, Int>;

        enum Type{
            STRING,
            FLOAT,
            INT
        };

        HolderType holder;
        Type type;

        Item(String);
        Item(Float);
        Item(Int);
    };
}//namespace BCA


#endif //BYTE_CODE_ASSEMBLER_ITEM_H
