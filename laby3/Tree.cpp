//
// Created by wyskw on 12.11.2024.
//

#include "Tree.h"

#include <iostream>

Tree::Tree()
: root() {}


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
    if( isVar(symbol)) {
        variables.insert(std::make_pair(symbol,0) );
    }

    return index + symbol.length() + 1;
}


std::string Tree::nextSymbol(const std::string& formula, int index) {
    if (index >= formula.size()) return "";
    size_t nextSpace = formula.find(' ', index);
    if (nextSpace == std::string::npos) {
        return formula.substr(index);  // Do końca
    }
    return formula.substr(index, nextSpace - index);
}

void Tree::printTree() {
    printTree(root);
    std::cout<< std::endl;
}

void Tree::printVars() {
    if(variables.empty())
        std::cout<<"There are no variables!";

    for (auto var: variables) {
        std::cout << var.first << ", ";
    }
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

bool Tree::isVar(const std::string &formula) {

    for(int i=0;i<formula.length();++i) {
        if(formula[i] > '9' || formula[i] < '0') {
            return true;
        }
    }

    return false;
}

Tree::~Tree() {
    delete root;
}

