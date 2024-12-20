//
// Created by wyskw on 29.11.2024.
//

#include "Error.h"

#include <future>

std::string Error::getErrorMessage() {
    return errorMessage;
}

Error::Error(const std::string &error)
:errorMessage(error) {}

Error::Error(const Error &other)
:errorMessage(other.errorMessage) {}

Error &Error::operator=(Error other) {

    if(this == &other) return *this;

    std::swap(errorMessage,other.errorMessage);

    return *this;
}

Error::~Error() {}

