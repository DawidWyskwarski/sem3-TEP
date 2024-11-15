//
// Created by wyskw on 12.11.2024.
//

#include "Node.h"

Node::Node(const std::string& constrName)
: name(constrName), parent(nullptr), left(nullptr), right(nullptr){}

Node::Node()
: name(INITIAL_NODE_VALUE), parent(nullptr), left(nullptr), right(nullptr){}

std::string Node::getName() {
    return name;
}
void Node::setName(const std::string& newName) {
    name = newName;
}

Node* Node::getLeft() const {
    return left;
}
void Node::setLeft(Node *newLeft) {
    left = newLeft;
}

Node* Node::getRight() const {
    return right;
}
void Node::setRight(Node *newRight) {
    right = newRight;
}

Node *Node::getParent() const {
    return parent;
}
void Node::setParent(Node *newParent) {
    parent = newParent;
}







