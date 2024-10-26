#include <iostream>
#include "Number.h"

int main() {

    Number number1;
    Number number2;
    number1 = -99;
    number2 = -3;
    std::cout<<"Number1: "<<number1.toStr()<<std::endl;
    std::cout<<"Number2: "<<number2.toStr()<<std::endl;

    Number number3 = number1 + number2;

    std::cout<<"Number1: "<<number1.toStr()<<std::endl;
    std::cout<<"Number2: "<<number2.toStr()<<std::endl;
    std::cout<<"Number3: "<<number3.toStr()<<std::endl;

    return 0;
}
