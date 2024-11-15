//
// Created by wyskw on 12.11.2024.
//
#ifndef TREE_H
#define TREE_H
#include <map>

#include "Node.h"
const std::string operators2el[] = {"+", "-", "*", "/"};
const std::string operators1el[] = {"sin", "cos"};

class Tree {
public:
    Tree();

    void buildTree(const std::string& formula);
    void printTree();

private:
    Node* root;
    std::map<std::string,int> variables;

    std::string nextSymbol(const std::string& formula, int i);

    bool isOperator2el(std::string symbol);
    bool isOperator1el(std::string symbol);
    void printTree(Node* cur);
};



#endif //TREE_H
