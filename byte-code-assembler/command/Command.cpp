//
// Created by a404m on 9/24/21.
//

#include "Command.h"
#include <utility>

using namespace BCA;

Command::Command(const std::string &s, std::vector<Item> il) : token(toToken(s)), operands(std::move(il)) {/*empty*/}

Command::Token Command::toToken(const std::string& str) {
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
    }else{
        return NO_COMMAND;
    }
}
