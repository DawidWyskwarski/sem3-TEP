//
// Created by wyskw on 12.11.2024.
//

#include "Tree.h"

#include <cmath>
#include <iostream>

Tree::Tree()
: root() {}

Tree::~Tree() {
    delete root;
}

void Tree::buildTree(const std::string &formula) {

    delete root;
    root = new Node();
    buildTree(formula,root,0);

}

int Tree::buildTree(const std::string& formula, Node *node, const int index) {

    std::string symbol = nextSymbol(formula,index);

    if(symbol.empty())
        return index;

    node -> setName(symbol);

    if( isOperator1el(symbol) ) {
        node -> setLeft(new Node());

        return buildTree(formula,node->getLeft(), index + symbol.length() + 1);
    }
    if ( isOperator2el(symbol) ) {
        node -> setLeft(new Node());
        node -> setRight(new Node());

        return buildTree(formula,node->getRight(), buildTree(formula, node->getLeft(), index+ symbol.length() + 1));
    }
    if( isVar(symbol) && variables.find(symbol) == variables.end() ) {
        variables.insert(std::make_pair(symbol,0) );
    }

    return index + symbol.length() + 1;
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

void Tree::printVars() {
    if(variables.empty())
        std::cout<<"There are no variables!";

    for (const auto& var: variables) {
        std::cout << var.first << " ";
    }
    std::cout<< std::endl;
}

void Tree::printResult(const std::string& values) {
    if (root == nullptr) {
        std::cout << "The tree is empty!" << std::endl;
    }else {

        int index = 0;
        for (auto& var: variables) {
            std::string value = nextSymbol(values,index);
            index += value.length() + 1;

            var.second = stringToInt(value);
        }

        if(index == values.length() + 1) {
            std::cout << compute(root) << std::endl;
        }else {
            std::cout << "Wrong number of values" << std::endl;
        }
    }
}

double Tree::compute(Node *cur) {

    std::string symbol = cur->getName();

    if (symbol == "+") {
        return compute(cur->getLeft() ) + compute(cur->getRight() );
    }
    if (symbol == "-") {
        return compute(cur->getLeft() ) - compute(cur->getRight() );
    }
    if (symbol == "*") {
        return compute(cur->getLeft() ) * compute(cur->getRight() );
    }
    if (symbol == "/") {
        return compute(cur->getLeft() ) / compute(cur->getRight() );
    }
    if (symbol == "sin") {
        return sin( compute(cur->getLeft()) );
    }
    if (symbol == "cos") {
        return cos( compute(cur->getLeft()) );
    }

    if(variables.find(symbol) != variables.end()) {
        return variables[symbol];
    }

    return stringToInt(symbol);
}

bool Tree::isOperator2el(const std::string& symbol) {

    for(const std::string & i : operators2el) {
        if (symbol == i) {
            return true;
        }
    }
    return false;
}

bool Tree::isOperator1el(const std::string& symbol) {

    for(const std::string & i : operators1el) {
        if (symbol == i) {
            return true;
        }
    }
    return false;
}

bool Tree::isVar(const std::string &formula) {

    for(int i=0;i<formula.length();++i) {
        if(formula[i] > '9' || formula[i] < '0') {
            return true;
        }
    }

    return false;
}

std::string Tree::nextSymbol(const std::string& formula, int index) {
    if (index >= formula.size()) return "";

    size_t nextSpace = formula.find(' ', index);

    if (nextSpace == std::string::npos) {
        return formula.substr(index);
    }
    return formula.substr(index, nextSpace - index);
}

int Tree::stringToInt(const std::string &number) {

    int result = number[0] - '0';

    for(int i=1;i<number.length();++i) {
        result *= 10;
        result += number[i] - '0';
    }

    return result;
}
