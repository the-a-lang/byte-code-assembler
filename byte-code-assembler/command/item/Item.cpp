//
// Created by a404m on 9/24/21.
//

#include "Item.h"

using namespace BCA;

Item::Item(String str) : holder(str), type(STRING) {/*empty*/}

Item::Item(Float f) : holder(f), type(FLOAT) {/*empty*/}

Item::Item(Int i) : holder(i), type(INT) {/*empty*/}
