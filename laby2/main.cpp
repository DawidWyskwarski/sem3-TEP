#include <iostream>
#include "Number.h"



int main() {

    unsigned long long n1 = 7352;
    unsigned long long n2 = 236;

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

    std::cout<<std::endl;

    number3 >= number1 >= number2;

    std::cout<<"Mod: "<<std::endl;
    std::cout<<"Number1: "<<number1.toStr()<<std::endl;
    std::cout<<"Number2: "<<number2.toStr()<<std::endl;

    int x;

    number2 >= x;
    std::cout<<"x: "<<x<<std::endl;

    123 >= number3 >= x >= number1 >= number2;

    std::cout<<"Number1: "<<number1.toStr()<<std::endl;
    std::cout<<"Number2: "<<number2.toStr()<<std::endl;
    std::cout<<"Number3: "<<number3.toStr()<<std::endl;
    std::cout<<"x: "<<x<<std::endl;

    return 0;
}
