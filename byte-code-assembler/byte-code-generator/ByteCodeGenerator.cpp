//
// Created by a404m on 10/5/21.
//

#include "ByteCodeGenerator.h"

using namespace BCA;

ByteCodeGenerator::ByteCodeGenerator(Parser p) : parser(std::move(p)) {
    setData();
    holder += CALL;
    holder += getName(parser.headerHolder.at("global"));
    setCode();
}

void ByteCodeGenerator::setData() {
    for(const auto &line : parser.dataHolder){
        holder += DECL_BY_VALUE;//DECL_BY_VALUE|name|size|value
        holder += getName(line.name);
        switch(line.type){
            case Data::INT:{
                holder += getName("INT");
            }
                break;
            case Data::FLOAT:///todo
            case Data::STRING:
            case Data::NO_TYPE:
            default:
                throw std::runtime_error("ByteCodeGenerator::setData");
        }
    }
}

void ByteCodeGenerator::setCode() {//DECL|name|size|var
    for(const auto &line : parser.codeHolder){
        switch(line.token){
            case Command::DECL:
                if(line.operands.size() != 3){
                    throw std::runtime_error("ByteCodeGenerator::setCode");
                }
                holder += DECL;
                holder += getName(line.operands[0].str);
                holder += getName(line.operands[1].str);
                holder += getName(line.operands[2].str);
                break;
            case Command::MOV:
                if(line.operands.size() != 2){
                    throw std::runtime_error("ByteCodeGenerator::setCode");
                }
                holder += MOV;
                holder += getName(line.operands.front().str);
                holder += getName(line.operands.back().str);
                break;
            case Command::ADD:
                if(line.operands.size() != 2){
                    throw std::runtime_error("ByteCodeGenerator::setCode");
                }
                holder += ADD;
                holder += getName(line.operands.front().str);
                holder += getName(line.operands.back().str);
                break;
            case Command::SUB:
                if(line.operands.size() != 2){
                    throw std::runtime_error("ByteCodeGenerator::setCode");
                }
                holder += SUB;
                holder += getName(line.operands.front().str);
                holder += getName(line.operands.back().str);
                break;
            case Command::MUL:
                if(line.operands.size() != 2){
                    throw std::runtime_error("ByteCodeGenerator::setCode");
                }
                holder += MUL;
                holder += getName(line.operands.front().str);
                holder += getName(line.operands.back().str);
                break;
            case Command::DIV:
                if(line.operands.size() != 2){
                    throw std::runtime_error("ByteCodeGenerator::setCode");
                }
                holder += DIV;
                holder += getName(line.operands.front().str);
                holder += getName(line.operands.back().str);
                break;
            case Command::CALL:
                if(line.operands.size() != 1){
                    throw std::runtime_error("ByteCodeGenerator::setCode");
                }
                holder += CALL;
                holder += toString(parser.labelHolder.at(line.operands.front().str));
                break;
            case Command::RET:
                if(!line.operands.empty()){
                    throw std::runtime_error("ByteCodeGenerator::setCode");
                }
                holder += RET;
                break;
            case Command::NO_COMMAND:
            default:
                throw std::runtime_error("ByteCodeGenerator::setCode");
        }
    }
}

template<typename T>
std::string ByteCodeGenerator::toString(T t) {
    T *temp = new T(t);
    auto size = sizeof(T);
    std::string result{reinterpret_cast<char*>(temp),size+1};
    delete temp;
    return result;
}

std::string ByteCodeGenerator::getName(const std::string& name) {
    return toString(name.size()) + name;
}
