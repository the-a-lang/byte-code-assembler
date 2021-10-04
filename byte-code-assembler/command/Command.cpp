//
// Created by a404m on 9/24/21.
//

#include "Command.h"
#include <stdexcept>

BCA::Command::Command(const std::string &s, const std::initializer_list<Item> &il) : token(toToken(s)), operands(il) {/*empty*/}

BCA::Command::Token BCA::Command::toToken(const std::string &str) {
    if(str == "DECL"){
        return DECL;
    }else if(str == "MOV"){
        return MOV;
    }else if(str == "ADD"){
        return ADD;
    }else if(str == "SUB"){
        return SUB;
    }else if(str == "MUL"){
        return MUL;
    }else if(str == "DIV"){
        return DIV;
    }else if(str == "CALL"){
        return CALL;
    }else if(str == "RET"){
        return RET;
    }else if(str == "PUSH"){
        return PUSH;
    }else if(str == "POP"){
        return POP;
    }else{
        throw std::runtime_error("BCA::Command::toToken");
    }
}
