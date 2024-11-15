//
// Created by wyskw on 12.11.2024.
//

#include "Tree.h"

#include <iostream>

Tree::Tree()
: root(nullptr) {}



std::string Tree::nextSymbol(const std::string& formula, int i) {

    while(i<formula.length() || formula[i] == ' ') {
        ++i;
    }
    std::string result;

    for(;i<formula.length() && formula[i] != ' ';++i) {
        result += formula[i];
    }

    return result;
}

void Tree::printTree() {
    printTree(root);
    std::cout<< std::endl;
}

void Tree::printTree(Node *cur) {
    if (cur != nullptr) {
        std::cout<< cur -> getName()<< " ";

        printTree(cur -> getLeft());
        printTree(cur -> getRight());
    }
}

bool Tree::isOperator2el(std::string symbol) {

    for(const std::string & i : operators2el) {
        if (symbol == i) {
            return true;
        }
    }
    return false;
}

bool Tree::isOperator1el(std::string symbol) {

    for(const std::string & i : operators1el) {
        if (symbol == i) {
            return true;
        }
    }
    return false;
}
