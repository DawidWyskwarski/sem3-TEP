//
// Created by wyskw on 12.11.2024.
//

#include "Node.h"

Node::Node(const std::string constrName)
: name(constrName){}

Node::Node(const Node& node):name(node.name){
    for(Node* child: node.children) {
        children.push_back(new Node(*child));
    }
}

Node::Node()
: name(INITIAL_NODE_VALUE){}

Node& Node::operator=(Node node) {

    std::swap(name, node.name);
    std::swap(children, node.children);

    return *this;
}


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

void Node::addBeginning(Node *node) {
    delete children.at(0);
    children.erase(children.begin());

    children.insert(children.begin(),node);
}

int Node::numberOfChildren() {
    return children.size();
}

Node::~Node() {
    for (auto child: children) {
        delete child;
    }
}
