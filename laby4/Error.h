//
// Created by wyskw on 29.11.2024.
//

#ifndef ERROR_H
#define ERROR_H
#include <string>


class Error {
public:
    Error(const std::string& error);
    Error(const Error& other);

    Error& operator=(Error other);

    std::string getErrorMessage();

    ~Error();
private:
    std::string errorMessage;
};



#endif //ERROR_H
