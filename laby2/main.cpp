#include <iostream>
#include "Number.h"

int main() {

    unsigned long long n1 = 983560;
    unsigned long long n2 = 9;

    Number number1;
    Number number2;
    number1 = n1;
    number2 = n2;
    std::cout<<"Number1: "<<number1.toStr()<<std::endl;
    std::cout<<"Number2: "<<number2.toStr()<<std::endl<<std::endl;

    Number number3 = number1 + number2;

    std::cout<<"Add: "<<std::endl;
    std::cout<<"Number3: "<<number3.toStr()<<std::endl;
    std::cout<<"Correct: "<<n1+n2<<std::endl;


    std::cout<<std::endl;

    number3 = number1 - number2;

    std::cout<<"Sub: "<<std::endl;
    std::cout<<"Number3: "<<number3.toStr()<<std::endl;
    std::cout<<"Correct: "<<n1-n2<<std::endl;

    std::cout<<std::endl;

    number3 = number1 * number2;

    std::cout<<"Multi: "<<std::endl;
    std::cout<<"Number3: "<<number3.toStr()<<std::endl;
    std::cout<<"Correct: "<<n1*n2<<std::endl;

    std::cout<<std::endl;

    number3 = number1 / number2;

    std::cout<<"Division: "<<std::endl;
    std::cout<<"Number3: "<<number3.toStr()<<std::endl;
    std::cout<<"Correct: "<<n1/n2<<std::endl;

    return 0;
}
