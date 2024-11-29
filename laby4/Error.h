//
// Created by wyskw on 29.11.2024.
//

#ifndef ERROR_H
#define ERROR_H
#include <string>


class Error {

    Error(const std::string& error);

    std::string getErrorMessage();


private:
    std::string errorMessage;
};



#endif //ERROR_H
