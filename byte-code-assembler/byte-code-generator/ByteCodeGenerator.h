//
// Created by a404m on 10/5/21.
//

#ifndef BYTE_CODE_ASSEMBLER_BYTECODEGENERATOR_H
#define BYTE_CODE_ASSEMBLER_BYTECODEGENERATOR_H

#include "../parser/Parser.h"

int main();

namespace BCA {
    class ByteCodeGenerator {
        friend int ::main();
    public:
        enum CommandInstructions{
            DECL_BY_VALUE = 1,
            DECL,
            MOV,
            ADD,
            SUB,
            MUL,
            DIV,
            CALL,
            RET,
        };
    private:
        Parser parser;
        std::string holder;
    public:
        explicit ByteCodeGenerator(Parser);

    private:
        void setData();
        void setCode();

        static std::string getName(const std::string&);

        template<typename T>
        static std::string toString(T t);
    };
}//namespace BCA


#endif //BYTE_CODE_ASSEMBLER_BYTECODEGENERATOR_H
