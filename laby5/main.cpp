#include <iostream>
#include "MySmartPointer.h"

int main() {

    MySmartPointer<int> t1 = new int(10);

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

    // assigning it to   
    return 0;
}
