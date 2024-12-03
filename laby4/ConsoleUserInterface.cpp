//
// Created by wyskw on 22.11.2024.
//

#include "ConsoleUserInterface.h"

#include <iostream>

ConsoleUserInterface::ConsoleUserInterface() {}


void ConsoleUserInterface::startSession() {

    std::cout<<START_MESSAGE<< std::endl;

    std::string input;

    while(input!=QUIT_OPERATOR) {
        std::cout << INPUT_SIGN;
        std::getline(std::cin,input);
        whichOperation(input);
    }
}

void ConsoleUserInterface::whichOperation(std::string& input) {

    std::string operation;
    std::string formula;
    Tree tmp;

    const int pivotPoint = findFirstSpace(input);

    if(pivotPoint == -1) {
        operation = input;
    }else {
        operation = input.substr(0,pivotPoint);
        formula = input.substr(pivotPoint+1);

        removeLeadingSpaces(formula);
        removeTrailingSpaces(formula);
    }

    if(operation == PRINT_OPERATOR && formula.empty() ) {
        Result<std::string,Error> result = tree.printTree();

        if(result.isSuccess()) {
            std::cout << result.getValue() << std::endl;
        }else {
            std::cout << result.getErrors()[0]->getErrorMessage() << std::endl;
        }
    }
    else if (operation == VARS_OPERATOR && formula.empty() ) {
        Result<std::string,Error> result = tree.printVars();

        if(result.isSuccess()) {
            std::cout << result.getValue() << std::endl;
        }else {
            std::cout << result.getErrors()[0]->getErrorMessage() << std::endl;
        }
    }
    else if (operation == ENTER_OPERATOR) {
        Result<void,Error> result = tree.buildTree(formula);

        if(!result.isSuccess()) {
            std::cout << result.getErrors()[0]->getErrorMessage() << std::endl;
        }
    }
    else if (operation == COMP_OPERATOR) {
        Result<double,Error> result = tree.printResult(formula);

        if(result.isSuccess()) {
            std::cout << result.getValue() << std::endl;
        }else {
            std::cout << result.getErrors()[0]->getErrorMessage() << std::endl;
        }
    }
    else if (operation == JOIN_OPERATOR) {
        tmp.buildTree(formula);

        tree = tree + tmp;

        std::cout << JOINED << std::endl;
        tree.printTree();
    }
    else if (operation == QUIT_OPERATOR) {
        input = QUIT_OPERATOR;
    }
    else std::cout<< OPERATION_ERROR <<std::endl;
}

int ConsoleUserInterface::findFirstSpace(const std::string& input) {
    for(int i=0;i<input.length();++i) {
        if (input[i] == ' ') {
            return i;
        }
    }
    return -1;
}

void ConsoleUserInterface::removeLeadingSpaces(std::string& str) {
    size_t startPos = 0;

    while (startPos < str.length() && str[startPos] == ' ') {
        ++startPos;
    }

    str.erase(0, startPos);
}

void ConsoleUserInterface::removeTrailingSpaces(std::string& str) {
    size_t endPos = str.length();

    while (endPos > 0 && str[endPos - 1] == ' ') {
        --endPos;
    }

    str.erase(endPos);
}