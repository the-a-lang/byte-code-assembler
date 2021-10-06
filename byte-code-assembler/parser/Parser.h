//
// Created by a404m on 10/5/21.
//

#ifndef BYTE_CODE_ASSEMBLER_PARSER_H
#define BYTE_CODE_ASSEMBLER_PARSER_H

#include "../lexer/Lexer.h"
#include "../data/Data.h"
#include <map>

namespace BCA {
    class Parser {
        friend class ByteCodeGenerator;
    private:
        std::map<std::string,std::string> headerHolder{
                {"global",""}
        };
        std::vector<Data> dataHolder;
        std::vector<Command> codeHolder;
        std::map<std::string,decltype(codeHolder)::size_type> labelHolder;
        Lexer lexer;

    public:
        explicit Parser(Lexer);

    private:
        inline void parseHeaderLine(std::vector<Lexed> &);
        inline void parseDataLine(std::vector<Lexed> &);
        inline void parseCodeLine(std::vector<Lexed> &);
    };
}//namespace BCA


#endif //BYTE_CODE_ASSEMBLER_PARSER_H
