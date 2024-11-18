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

int Tree::buildTree(const std::string& formula, Node *node, int index) {

    std::string symbol = nextSymbol(formula,index);

    node -> setName(symbol);

    if( operators.find(symbol) != operators.end() ) {

        for(int i=0;i < operators.at(symbol) ;++i) {
            node->addChild(new Node());
            index = buildTree(formula,node->getChildAt(i),index + symbol.length() + 1);
        }
    }else if( isVar(symbol) && variables.find(symbol) == variables.end() ) {
        variables.insert(std::make_pair(symbol,0) );
    }

    return index;
}

void Tree::printTree() {
    printTree(root);
    std::cout<< std::endl;
}

void Tree::printTree(Node *cur) {
    if (cur != nullptr) {
        std::cout<< cur -> getName()<< " ";

        for (int i=0;i<cur->numberOfChildren();++i) {
            printTree( cur->getChildAt(i) );
        }
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

        if(index == values.length() + 1 || (values.empty() && variables.empty())) {
            std::cout << compute(root) << std::endl;
        }else{
            std::cout << "Wrong number of values" << std::endl;
        }
    }
}

double Tree::compute(Node *cur) {

    std::string symbol = cur->getName();

    if (symbol == "+") {
        return compute(cur->getChildAt(0) ) + compute(cur->getChildAt(1) );
    }
    if (symbol == "-") {
        return compute(cur->getChildAt(0) ) - compute(cur->getChildAt(1) );
    }
    if (symbol == "*") {
        return compute(cur->getChildAt(0) ) * compute(cur->getChildAt(1) );
    }
    if (symbol == "/") {
        return compute(cur->getChildAt(0) ) / compute(cur->getChildAt(1) );
    }
    if (symbol == "sin") {
        return sin( compute(cur->getChildAt(0) ));
    }
    if (symbol == "cos") {
        return cos( compute(cur->getChildAt(0)) );
    }

    if(variables.find(symbol) != variables.end()) {
        return variables[symbol];
    }

    return stringToInt(symbol);
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
    if (index >= formula.size()) return INITIAL_NODE_VALUE;

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
