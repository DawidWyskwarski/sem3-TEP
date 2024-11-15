//
// Created by wyskw on 12.11.2024.
//

#ifndef NODE_H
#define NODE_H
#include <string>

#define INITIAL_NODE_VALUE "1"

class Node {

public:
    Node(const std::string& constrName);
    Node();

    std::string getName();
    void setName(const std::string& newName);

    Node* getLeft() const;
    Node* getRight() const;
    Node* getParent() const;

    void setLeft(Node* newLeft);
    void setRight(Node* newRight);
    void setParent(Node* newParent);
    //Node was adopted

private:
    std::string name;
    Node* parent;
    Node* left;
    Node* right;
};



#endif //NODE_H
