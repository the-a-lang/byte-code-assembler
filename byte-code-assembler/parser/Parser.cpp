//
// Created by a404m on 10/5/21.
//

#include "Parser.h"

using namespace BCA;

Parser::Parser(BCA::Lexer l) : lexer(std::move(l)) {
    enum Section{
        NONE,
        HEADER,
        DATA,
        CODE
    };
    Section section = NONE;

    for(auto& line : lexer.holder){
        if(line.front().token == Lexed::KEYWORD && line.front().str == "SECTION"){
            if(line.size() < 2 || line[1].token != Lexed::ID){
                throw std::runtime_error("Parser::Parser");
            }
            auto sectionName = line[1].str;
            toUpper(sectionName);

            if(sectionName == "HEADER"){
                section = HEADER;
            }else if(sectionName == "DATA"){
                section = DATA;
            }else if(sectionName == "CODE"){
                section = CODE;
            }
            continue;
        }
        switch (section) {
            case HEADER:
                parseHeaderLine(line);
                break;
            case DATA:
                parseDataLine(line);
                break;
            case CODE:
                parseCodeLine(line);
                break;
            default:
                throw std::runtime_error("Parser::Parser");
        }
    }
    lexer.holder.clear();
}

void Parser::parseHeaderLine(std::vector<Lexed> &line) {
    if(line.size() != 2){
        throw std::runtime_error("Parser::parseDataLine");
    }if(line[0].token != Lexed::ID || (line[1].token != Lexed::ID && line[1].token != Lexed::KEYWORD)){
        throw std::runtime_error("Parser::parseDataLine");
    }
    headerHolder.at(line[0].str) = line[1].str;
}

void Parser::parseDataLine(std::vector<Lexed> &line) {//line should be line ->            name type value
    if(line.size() != 3){
        throw std::runtime_error("Parser::parseDataLine");
    }if(line[0].token != Lexed::ID || line[1].token != Lexed::KEYWORD){
        throw std::runtime_error("Parser::parseDataLine");
    }
    toUpper(line[1].str);
    dataHolder.emplace_back(line[0].str,Data::toType(line[1].str),line[2].str);
}

void Parser::parseCodeLine(std::vector<Lexed> &line) {
    if(line.front().token == Lexed::ID){
        if(line[1].token == Lexed::SYMBOL && line[1].str == ":"){
            if(labelHolder.find(line.front().str) == labelHolder.end()){
                labelHolder[line.front().str] = codeHolder.size();
                if(line.size() == 2){
                    return;
                }
                line.erase(line.begin(),line.begin()+2);
            }else{
                throw std::runtime_error("Parser::parseCodeLine");
            }
        }else{
            throw std::runtime_error("Parser::parseCodeLine");
        }
    }
    Command result{line.front().str};
    if(result.token == Command::NO_COMMAND){
        throw std::runtime_error("Parser::parseCodeLine");
    }
    Item::Type type;
    bool needsComma = false;
    for(auto it = line.begin()+1,end = line.end();it < end;++it){
        if(needsComma){
            if(it->token == Lexed::SYMBOL && it->str == ","){
                needsComma = false;
                continue;
            }else{
                throw std::runtime_error("Parser::parseCodeLine");
            }
        }
        switch (it->token) {
            case Lexed::ID:
                type = Item::ID;
                break;
            case Lexed::KEYWORD:
                type = Item::KEYWORD;
                break;
            case Lexed::NUMBER:
            case Lexed::STRING:
            case Lexed::SYMBOL:
            case Lexed::NONE:
            default:
                throw std::runtime_error("Parser::parseCodeLine");
        }
        result.operands.emplace_back(it->str,type);
        needsComma = true;
    }
    codeHolder.push_back(result);
}
