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

void Tree::buildTree(std::string &formula) {

    delete root;
    root = new Node();
    int index = 0;
    removeLeadingSpaces(formula);
    removeTrailingSpaces(formula);
    buildTree(formula,root,index);

}

void Tree::buildTree(const std::string& formula, Node *node,int& index) {

    std::string symbol = nextSymbol(formula,index);

    node -> setName(symbol);

    if( operators.find(symbol) != operators.end() ) {

        for(int i=0;i < operators.at(symbol) ;++i) {
            node->addChild(new Node());

            index+=1;
            buildTree(formula,node->getChildAt(i),index);
        }
    }else if( isVar(symbol) && variables.find(symbol) == variables.end() ) {
        variables.insert(std::make_pair(symbol,0) );
    }
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

void Tree::printResult(std::string& values) {
    if (root == nullptr) {
        std::cout << "The tree is empty!" << std::endl;
        return;
    }

    int index = 0;

    removeLeadingSpaces(values);
    removeTrailingSpaces(values);

    for (auto& var: variables) {
        if (index >= values.length()) {
            std::cout<<"Wrong number of values"<< std::endl;
            return;
        }

        std::string value = nextSymbol(values,index);

        var.second = stringToInt(value);
    }

    if(index == values.length()) {
        std::cout << compute(root) << std::endl;
        return;
    }

    std::cout << "Wrong number of values" << std::endl;
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

std::string Tree::nextSymbol(const std::string& formula, int& index) {
    if (index >= formula.length())
        return INITIAL_NODE_VALUE;

    while (index < formula.length() && formula[index] == ' ') {
        ++index;
    }

    if (index >= formula.length())
        return INITIAL_NODE_VALUE;

    bool invalidChar = false;
    std::string symbol;

    for (; index < formula.length() && formula[index] != ' '; ++index) {
        char c = formula[index];

        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )) {
            invalidChar = true;
        }

        symbol += c;
    }

    if(operators.find(symbol) != operators.end()) {
        return symbol;
    }

    if (invalidChar) {
        return nextSymbol(formula, index);
    }

    return symbol;
}

int Tree::stringToInt(const std::string &number) {

    int result = number[0] - '0';

    for(int i=1;i<number.length();++i) {
        result *= 10;
        result += number[i] - '0';
    }

    return result;
}

void Tree::removeLeadingSpaces(std::string& str) {
    size_t startPos = 0;

    while (startPos < str.length() && str[startPos] == ' ') {
        ++startPos;
    }

    str.erase(0, startPos);
}

void Tree::removeTrailingSpaces(std::string& str) {
    size_t endPos = str.length();

    while (endPos > 0 && str[endPos - 1] == ' ') {
        --endPos;
    }

    str.erase(endPos);
}