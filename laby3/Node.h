//
// Created by wyskw on 12.11.2024.
//

#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

#define INITIAL_NODE_VALUE "1"

class Node {

public:
    Node(const std::string constrName);
    Node();

    std::string getName();
    void setName(std::string newName);

    Node* getChildAt(int index);
    void addChild(Node* newNode);

    int numberOfChildren();

    ~Node();

private:
    std::string name;
    std::vector<Node*> children;
};



#endif //NODE_H
