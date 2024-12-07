//
// Created by wyskw on 12.11.2024.
//
#ifndef TREE_H
#define TREE_H
#include <map>

#include "Node.h"
#include "Result.h"
#include "Error.h"

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

    Result<void,Error> buildTree(std::string& formula);
    Result<std::string,Error> printTree();
    Result<std::string,Error> printVars();
    Result<double,Error> printResult(std::string& values);
    Result<Tree,Error> operator+(Tree& tree);
    bool partialSwap(Tree& tree, const std::string& token);

    ~Tree();

private:
    Node* root;
    std::map<std::string,int> variables;

    void printTree(Node* cur,std::string& result);
    Result<void,Error> buildTree(const std::string& formula, Node* node, int& index);
    double compute(Node* cur);

    Node* findWithInChildren(const std::string& token);

    bool isVar(const std::string& formula);

    Result<std::string,Error> nextSymbol(const std::string& formula, int& index);

    int stringToInt(const std::string& number);
};



#endif //TREE_H
