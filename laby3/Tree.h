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

    void buildTree(std::string& formula);
    void printTree();
    void printVars();
    void printResult(std::string& values);

    ~Tree();

private:
    Node* root;
    std::map<std::string,int> variables;

    void printTree(Node* cur);
    void buildTree(const std::string& formula, Node* node, int& index);
    double compute(Node* cur);

    bool isVar(const std::string& formula);

    std::string nextSymbol(const std::string& formula, int& index);

    void removeLeadingSpaces(std::string& str);
    void removeTrailingSpaces(std::string& str);

    int stringToInt(const std::string& number);
};



#endif //TREE_H
