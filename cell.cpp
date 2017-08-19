//
// Created by miguel on 11/08/17.
//

#include <cstdlib>
#include "cell.h"

cell::cell() {}

void cell::fill() {
    value = rand() % 4 < 3 ? 2 : 4;
    isEmpty = false;
}
