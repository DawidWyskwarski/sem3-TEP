#include <iostream>
#include "MySmartPointer.h"
#include "UniquePointer.h"

int main() {

    /*MySmartPointer<int> t1 = new int(10);

    std::cout << "Only t1:" << std::endl;
    std::cout << *t1 << " " << t1.getCounter() << std::endl;

    if(true) {
        MySmartPointer<int> t2 = t1;

        std::cout << "t1 and t2:" << std::endl;

        std::cout << "t1:";
        std::cout << *t1 << " " << t1.getCounter() << std::endl;

        std::cout << "t2:";
        std::cout << *t2 << " " << t2.getCounter() << std::endl;

        std::cout << "change" << std::endl;
        *t2 = 12;

        std::cout << "t1:";
        std::cout << *t1 << " " << t1.getCounter() << std::endl;

        std::cout << "t2:";
        std::cout << *t2 << " " << t2.getCounter() << std::endl;

    }

    std::cout << "t2 is no more:" << std::endl;

    std::cout << "t1:";
    std::cout << *t1 << " " << t1.getCounter() << std::endl;

    */

    UniquePointer<int> u1 = new int(10);
    UniquePointer<int> u2 = new int(20);

    std::cout << "u1: " << *u1 << std::endl;
    std::cout << "u2: " << *u2 << std::endl;

    u1 = u2;

    std::cout << std::endl;

    std::cout << "u1: " << *u1 << std::endl;
    std::cout << "u2: " << *u2 << std::endl;


    return 0;
}
