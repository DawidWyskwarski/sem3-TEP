//
// Created by wyskw on 12.11.2024.
//
#ifndef TREE_H
#define TREE_H
#include <map>

#include "Node.h"

const std::map<std::string,int> operators = {{"+",2},{"-",2},{"*",2},{"/",2},{"sin",1},{"cos",1}};

class Tree {
public:
    Tree();

    void buildTree(const std::string& formula);
    void printTree();
    void printVars();
    void printResult(const std::string& values);

    ~Tree();

private:
    Node* root;
    std::map<std::string,int> variables;

    void printTree(Node* cur);
    int buildTree(const std::string& formula, Node* node, int index);
    double compute(Node* cur);

    bool isVar(const std::string& formula);

    std::string nextSymbol(const std::string& formula, int index);

    int stringToInt(const std::string& number);
};



#endif //TREE_H
