//
// Created by a404m on 9/24/21.
//

#include "functions.h"
#include <string>
#include "../command/Command.h"
#include "../data/Data.h"

namespace BCA{
    extern bool isStringMarker(char c){
        return c == '\"' || c == '\'';
    }
    extern bool isNumber(char c){
        return c >= '0' && c <= '9';
    }
    extern bool isAlphabet(char c){
        return std::isalpha(c) || c == '_';
    }
    extern bool isSymbol(char c){
        return c == ',' || c == ':';
    }
    extern bool isSpace(char c){
        return std::isspace(c);
    }
    extern bool isKeyword(std::string str){
        toUpper(str);
        return Command::toToken(str) || Data::toType(str) || str == "SECTION";
    }
    extern void toUpper(std::string &str){
        for(auto& c : str)
            c = static_cast<char>(std::toupper(c));
    }
}//namespace BCA