//
// Created by a404m on 10/5/21.
//

#include "Data.h"
#include <stdexcept>

using namespace BCA;

Data::Data(std::string n, Data::Type t,std::string v) : name(std::move(n)), value(std::move(v)), type(t) {/*empty*/}

Data::Type Data::toType(const std::string &str) {
    if(str == "INT"){
        return INT;
    }else if(str == "FLOAT"){
        return FLOAT;
    }else if(str == "STRING"){
        return STRING;
    }else{
        return NO_TYPE;
    }
}
