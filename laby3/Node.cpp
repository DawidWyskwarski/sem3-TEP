//
// Created by wyskw on 12.11.2024.
//

#include "Node.h"

Node::Node(const std::string& constrName) : parent(nullptr), left(nullptr), right(nullptr) {
    name = constrName;
}

Node::Node(const std::string &constrName, Node *constrParent, Node *constrLeft, Node *constrRight)
: name(constrName) , parent(constrParent), left(constrLeft), right(constrRight) {}


Node* Node::getLeft() const {
    return left;
}

Node* Node::getRight() const {
    return right;
}

Node *Node::getParent() const {
    return parent;
}

std::string Node::getName() {
    return name;
}

void Node::setName(const std::string& newName) {
    name = newName;
}





