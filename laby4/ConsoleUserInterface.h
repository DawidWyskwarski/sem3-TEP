//
// Created by wyskw on 22.11.2024.
//

#ifndef CONSOLEUSERINTERFACE_H
#define CONSOLEUSERINTERFACE_H
#include "Tree.h"
#include "Result.h"
#include "Error.h"

#define START_MESSAGE "Enter the operation you want to perform:\nenter <formula> - builds tree based on the formula\nvars - displays variables in the tree\nprint - prints tree\ncomp <var0> <var1> ... <varN> - computes the tree\njoin <formula> - joins the the current tree with a new one\nquit - quits session"

#define ENTER_OPERATOR "enter"
#define VARS_OPERATOR "vars"
#define PRINT_OPERATOR "print"
#define COMP_OPERATOR "comp"
#define JOIN_OPERATOR "join"
#define QUIT_OPERATOR "quit"
#define INPUT_SIGN ">"
#define OPERATION_ERROR "You've entered a wrong operation"
#define JOINED "Joined tree: "

class ConsoleUserInterface {
public:
    ConsoleUserInterface();
    void startSession();

private:
    int findFirstSpace(const std::string& input);
    void whichOperation(std::string& input);

    void removeTrailingSpaces(std::string& str);
    void removeLeadingSpaces(std::string& str);

    Tree tree;
};



#endif //CONSOLEUSERINTERFACE_H
