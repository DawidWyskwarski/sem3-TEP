//
// Created by wyskw on 12.11.2024.
//
#ifndef TREE_H
#define TREE_H
#include <map>

#include "Node.h"

#define EMPTY_TREE "The tree is empty!"
#define NO_VARS "There are no variables in the tree!"
#define WRONG_VARS "Wrong number of values!"
#define WRONG_VAR_NAME " includes invalid characters and will be skipped!"
#define WRONG_FORMULA "Inputted formula had mistakes, will process:"
#define INSTEAD "instead!"
#define WRONG_VARS_VALUES "One of the values is not a number!"

const std::map<std::string,int> operators = {{"+",2},{"-",2},{"*",2},{"/",2},{"sin",1},{"cos",1}};

class Tree {
public:
    Tree();
    Tree(const Tree& tree);
    Tree& operator=(Tree tree);

    void buildTree(std::string& formula);
    void printTree();
    void printVars();
    void printResult(std::string& values);
    Tree operator+(Tree& tree);


    ~Tree();

private:
    Node* root;
    std::map<std::string,int> variables;

    void printTree(Node* cur);
    void buildTree(const std::string& formula, Node* node, int& index);
    double compute(Node* cur);

    bool isVar(const std::string& formula);

    std::string nextSymbol(const std::string& formula, int& index);

    int stringToInt(const std::string& number);
};



#endif //TREE_H
