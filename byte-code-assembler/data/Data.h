//
// Created by a404m on 10/5/21.
//

#ifndef BYTE_CODE_ASSEMBLER_DATA_H
#define BYTE_CODE_ASSEMBLER_DATA_H

#include <string>

namespace BCA {
    struct Data {
    public:
        enum Type{
            NO_TYPE = 0,
            INT,
            FLOAT,
            STRING
        };

        std::string name;
        Type type;
        std::string value;

        Data(std::string, Type, std::string);

        static Type toType(const std::string&);
    };
}//namespace BCA


#endif //BYTE_CODE_ASSEMBLER_DATA_H
