//
// Created by a404m on 10/4/21.
//

#include "Lexer.h"

using namespace BCA;

Lexer::Lexer(std::string s) : str(std::move(s)), holder() {
    auto lexed = Lexed("",Lexed::NONE);
    std::vector<Lexed> line;

    for(auto it = str.begin(), end = str.end();it < end;++it){
        auto& current = *it;
        if(lexed.token == Lexed::STRING){
            if(current == lexed.str.front()){
                lexed.str.erase(0);
                push_clear(line,lexed);
                continue;
            }else if(current == '\\'){
                switch (*(++it)) {
                    case '\"':
                        lexed.str += '\"';
                        break;
                    case '\'':
                        lexed.str += '\'';
                        break;
                    case '\\':
                        lexed.str += '\\';
                        break;
                    case 'n':
                        lexed.str += '\n';
                        break;
                    case 'a':
                        lexed.str += '\a';
                        break;
                    case 'b':
                        lexed.str += '\b';
                        break;
                    case 'v':
                        lexed.str += '\v';
                        break;
                    case 't':
                        lexed.str += '\t';
                        break;
                    case 'r':
                        lexed.str += '\r';
                        break;
                    case 'f':
                        lexed.str += '\f';
                        break;
                    case '0':
                        lexed.str += '\0';
                        break;
                    default:
                        throw std::runtime_error("Lexer::Lexer");
                }
                continue;
            }
        }else if(current == '\n'){
            push_clear_ifn_emtpy(line,lexed);
            if(!line.empty()){
                holder.push_back(line);
                line.clear();
            }
            continue;
        }else if(isSpace(current)){
            push_clear_ifn_emtpy(line,lexed);
            continue;
        }else if(isStringMarker(current)){
            push_clear_ifn_emtpy(line,lexed);
            lexed.token = Lexed::STRING;
        }else if(isAlphabet(current) || (lexed.token == Lexed::ID && isNumber(current))){
            if(lexed.token != Lexed::ID) {
                push_clear_ifn_emtpy(line, lexed);
                lexed.token = Lexed::ID;
            }
        }else if(isSymbol(current)){
            if(lexed.token != Lexed::SYMBOL) {
                push_clear_ifn_emtpy(line, lexed);
                lexed.token = Lexed::SYMBOL;
            }
        }else if(isNumber(current) || (lexed.token == Lexed::NUMBER && current == '.')){
            if(lexed.token != Lexed::NUMBER) {
                push_clear_ifn_emtpy(line, lexed);
                lexed.token = Lexed::NUMBER;
            }
        }else if(current == ';'){
            for(;it < end && *it != '\n';++it);
            --it;
            continue;
        }else{
            throw std::runtime_error("Lexer::Lexer");
        }
        lexed.str += current;
    }
}

void Lexer::push_clear(std::vector<Lexed> &line, Lexed &lexed) {
    if(lexed.token == Lexed::ID){
        if(isKeyword(lexed.str)){
            lexed.token = Lexed::KEYWORD;
            toUpper(lexed.str);
        }
    }
    line.push_back(lexed);
    lexed.clear();
}

void Lexer::push_clear_ifn_emtpy(std::vector<Lexed> &line, Lexed &lexed) {
    if(!lexed.str.empty()){
        push_clear(line,lexed);
    }
}
