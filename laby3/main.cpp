#include <iostream>

int findFirstSpace(const std::string& input) {
    for(int i=0;i<input.length();++i) {
        if (input[i] == ' ') {
            return i;
        }
    }
    return -1;
}


void whichOperation(const std::string& input) {

    std::string operation;

    const int pivotPoint = findFirstSpace(input);

    if(pivotPoint == -1) {
        operation = input;
    }else {
        operation = input.substr(0,pivotPoint);
    }

    if(operation == "print" && operation == input) {
        std::cout<<"You wanted to print"<<std::endl;
    }
    else if (operation == "vars" && operation==input) {
        std::cout<<"You wanted to output all of the variables"<<std::endl;
    }
    else if (operation == "enter") {
        const std::string formula = input.substr(pivotPoint+1);
        std::cout<<"You wanted to enter the " << formula <<"!"<< std::endl;
    }
    else if (operation == "comp") {
        const std::string vals = input.substr(pivotPoint+1);
        std::cout<<"You wanted to compute the tree with vars being" << vals <<"!"<< std::endl;
    }
    else if (operation == "join") {
        const std::string formulaToJoin = input.substr(pivotPoint+1);
        std::cout<<"You wanted to join tree with the " << formulaToJoin <<"!"<< std::endl;
    }
    else if (operation == "quit") {}
    else std::cout<<"You've entered a wrong operation" + operation<<std::endl;
}

int main() {

    std::cout<<"Enter the operation you want to perform:\n"
               "enter <formula>\n"
               "vars\n"
               "print\n"
               "comp <var0> <var1> ... <varN>\n"
               "join <formula>\n"
               "quit"<<std::endl;

    std::string input;

    while(input!="quit") {
        std::cout<<">";
        std::getline(std::cin,input);
        whichOperation(input);
    }

    return 0;
}
