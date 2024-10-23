#include <iostream>
#include "Number.h"

int main() {

    Number number;
    number = 123;

    std::cout<<number.toStr()<<std::endl;
    return 0;
}
