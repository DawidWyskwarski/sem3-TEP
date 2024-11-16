//
// Created by wyskw on 12.11.2024.
//

#ifndef NODE_H
#define NODE_H
#include <string>

#define INITIAL_NODE_VALUE "1"

class Node {

public:
    Node(std::string constrName);
    Node();

    std::string getName();
    void setName(std::string newName);

    Node* getLeft() const;
    Node* getRight() const;

    void setLeft(Node* newLeft);
    void setRight(Node* newRight);

    ~Node();

private:
    std::string name;
    Node* left;
    Node* right;
};



#endif //NODE_H
