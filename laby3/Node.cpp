//
// Created by wyskw on 12.11.2024.
//

#include "Node.h"

Node::Node(const std::string constrName)
: name(constrName){}

Node::Node()
: name(INITIAL_NODE_VALUE){}

std::string Node::getName() {
    return name;
}

void Node::setName(const std::string newName) {
    name = newName;
}

void Node::addChild(Node* newNode) {
    children.push_back(newNode);
}

Node* Node::getChildAt(int index) {
    return children.at(index);
}

int Node::numberOfChildren() {
    return children.size();
}

Node::~Node() {
    for (auto child: children) {
        delete child;
    }
}
