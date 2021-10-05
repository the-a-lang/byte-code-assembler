//
// Created by a404m on 9/24/21.
//

#ifndef BYTE_CODE_ASSEMBLER_FUNCTIONS_H
#define BYTE_CODE_ASSEMBLER_FUNCTIONS_H                            b

#include <string>

namespace BCA{
    extern bool isStringMarker(char);
    extern bool isNumber(char);
    extern bool isAlphabet(char);
    extern bool isSymbol(char);
    extern bool isSpace(char);
    extern bool isKeyword(std::string);
    extern void toUpper(std::string&);
}//namespace BCA

#endif //BYTE_CODE_ASSEMBLER_FUNCTIONS_H
