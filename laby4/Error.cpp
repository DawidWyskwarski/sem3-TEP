//
// Created by wyskw on 29.11.2024.
//

#include "Error.h"

std::string Error::getErrorMessage() {
    return errorMessage;
}

Error::Error(const std::string &error):errorMessage(error) {}
