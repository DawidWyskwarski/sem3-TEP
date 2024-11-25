#include <iostream>

#include "ConsoleUserInterface.h"
#include "Tree.h"




int main() {

    //ConsoleUserInterface cui;
    //cui.startSession();

    Tree t1;
    std::string f1 = "* 3 x";
    std::string f2 = "* x y";
    t1.buildTree(f1);

    Tree t2;
    t2.buildTree(f2);

    std::cout << "t1:" << std::endl;
    t1.printTree();

    std::cout << "t2:" << std::endl;
    t2.printTree();

    std::cout<<t1.partialSwap(t2,"+")<< std::endl;

    std::cout << "after swap:" << std::endl;

    std::cout << "t1:" << std::endl;
    t1.printTree();

    std::cout << "t2:" << std::endl;
    t2.printTree();

    std::cout << "change t2:" << std::endl;
    std::string f3 = "";
    t2.buildTree(f3);

    std::cout << "t1:" << std::endl;
    t1.printTree();

    std::cout << "t2:" << std::endl;
    t2.printTree();

    return 0;
}
