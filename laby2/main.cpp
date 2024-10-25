#include <iostream>
#include "Number.h"

int main() {

    Number number1;
    Number number2;
    number2 = 3210;
    std::cout<<"Number1: "<<number1.toStr()<<std::endl;
    std::cout<<"Number2: "<<number2.toStr()<<std::endl;

    number1 = number2;
    number2 = 1;

    std::cout<<"Number1: "<<number1.toStr()<<std::endl;
    std::cout<<"Number2: "<<number2.toStr()<<std::endl;
    return 0;
}
