//
// Created by a404m on 10/5/21.
//

#include "Lexed.h"

using namespace BCA;

Lexed::Lexed(std::string s, Lexed::Token t): str(std::move(s)), token(t) {/*empty*/}

void Lexed::clear() {
    str.clear();
    token = NONE;
}
