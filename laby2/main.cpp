#include <iostream>
#include "Number.h"

int main() {

    Number number1;
    Number number2;
    number2 = 558328;
    number1 = 4125;
    std::cout<<"Number1: "<<number1.toStr()<<std::endl;
    std::cout<<"Number2: "<<number2.toStr()<<std::endl;

    Number number3 = number1 + number2;

    std::cout<<"Add: "<<std::endl;
    std::cout<<"Number3: "<<number3.toStr()<<std::endl;

    std::cout<<std::endl;

    number3 = number1 - number2;

    std::cout<<"Sub: "<<std::endl;
    std::cout<<"Number3: "<<number3.toStr()<<std::endl;

    return 0;
}
