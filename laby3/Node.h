//
// Created by wyskw on 12.11.2024.
//

#ifndef NODE_H
#define NODE_H
#include <string>


class Node {

public:
    Node(const std::string& constrName);
    Node(const std::string &constrName, Node *constrParent, Node *constrLeft, Node *constrRight);

    std::string getName();
    void setName(const std::string& newName);

    Node* getLeft() const;
    Node* getRight() const;
    Node* getParent() const;

private:
    std::string name;
    Node* parent;
    Node* left;
    Node* right;
};



#endif //NODE_H
