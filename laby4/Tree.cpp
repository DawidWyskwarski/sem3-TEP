//
// Created by wyskw on 12.11.2024.
//

#include "Tree.h"

#include <cmath>
#include <future>
#include <iostream>
#include <queue>

Tree::Tree()
: root(nullptr) {}

Tree::Tree(const Tree& tree): root(nullptr) {
    if(tree.root != nullptr) {
        root = new Node(*tree.root);
    }
    variables = tree.variables;
}

Tree::~Tree() {
    delete root;
}

Tree& Tree::operator=(Tree tree) {
    if(this == &tree) return *this;

    std::swap(root,tree.root);
    std::swap(variables,tree.variables);

    return *this;
}

void Tree::buildTree(std::string &formula) {

    delete root;
    variables.clear();

    root = new Node();

    int index = 0;
    buildTree(formula,root,index);

    if(index != formula.length() || formula.empty()) {
        std::cout << WRONG_FORMULA << std::endl;
        printTree();
        std::cout << INSTEAD << std::endl;
    }
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

bool Tree::partialSwap(Tree &tree, const std::string& token) {

    Node* t1 = this->findWithInChildren(token);
    Node* t2 = tree.findWithInChildren(token);

    if(t1 == nullptr || t2 == nullptr)
        return false;

    std::swap(*t1,*t2);
    return true;
}

Node* Tree::findWithInChildren(const std::string &token) {

    std::queue<Node*> queue;
    queue.push(root);

    while(!queue.empty()) {
        Node* cur = queue.front();
        queue.pop();

        if(cur->getName() == token) {
            return cur;
        }

        for(int i=0;i<cur->numberOfChildren();++i) {
            queue.push(cur->getChildAt(i));
        }
    }

    return nullptr;
}

void Tree::printTree() {
    if(root == nullptr) {
        std::cout << EMPTY_TREE;
    }

    printTree(root);
    std::cout << std::endl;
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
        std::cout<< NO_VARS;

    for (const auto& var: variables) {
        std::cout << var.first << " ";
    }
    std::cout<< std::endl;
}

void Tree::printResult(std::string& values) {
    if (root == nullptr) {
        std::cout << EMPTY_TREE << std::endl;
        return;
    }

    for(int i=0;i<values.length();++i) {
        if( !( (values[i]>='0' && values[i]<='9') || values[i]==' ' )  ) {
            std::cout<< WRONG_VARS_VALUES << std::endl;
            return;
        }
    }

    int index = 0;

    for (auto& var: variables) {
        if (index >= values.length()) {
            std::cout<< WRONG_VARS << std::endl;
            return;
        }

        std::string value = nextSymbol(values,index);

        var.second = stringToInt(value);
    }

    if(index == values.length()) {
        std::cout << compute(root) << std::endl;
    }else {
        std::cout << WRONG_VARS << std::endl;
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

Tree Tree::operator+(Tree& tree) {
    if (root == nullptr) {
        return tree;
    }

    Tree result = *this;

    if(root->numberOfChildren() == 0) {
        result = tree;
    }else {

        Node* cur = result.root;

        while(cur->getChildAt(0)->numberOfChildren() > 0) {
            cur = cur->getChildAt(0);
        }

        if (isVar(cur->getChildAt(0)->getName() )) {
            result.variables.erase( result.variables.find(cur->getChildAt(0)->getName()) );
        }

        Node* newRoot = new Node(*tree.root);
        cur->addBeginning(newRoot);
    }

    for (const auto& [key, value] : tree.variables) {
        if (result.variables.find(key) == result.variables.end()) {
            result.variables[key] = value;
        }
    }

    return result;
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
        std::cout << symbol << WRONG_VAR_NAME << std::endl;
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