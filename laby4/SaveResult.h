//
// Created by wyskw on 05.12.2024.
//

#ifndef SAVERESULT_H
#define SAVERESULT_H
#include <cmath>
#include <fstream>

#include "Result.h"
#include "Error.h"
#include "Tree.h"

#define BASE_FILE_NAME "result"
#define FILE_FORMAT ".txt"
#define NOT_OPEN "Couldn't open the file!"

template<typename T>
class SaveResult {
public:
    SaveResult();
    SaveResult(const std::string& file);

    Result<void,Error> save(Result<T,Error>& result);

private:
    std::string file;
};

template<typename T>
SaveResult<T>::SaveResult():file(BASE_FILE_NAME) {}

template<typename T>
SaveResult<T>::SaveResult(const std::string &file):file(file) {};

template<typename T>
Result<void,Error> SaveResult<T>::save(Result<T, Error> &result) {
    std::ofstream outFile;;

    outFile.open(file + FILE_FORMAT);

    if(outFile.is_open()) {
        if(!result.isSuccess()) {
            for(Error* error: result.getErrors()) {
                outFile << error->getErrorMessage() << std::endl;
            }
        }
        outFile.close();
        return Result<void,Error>::ok();
    }

    return Result<void,Error>::fail(new Error(NOT_OPEN));
}

template<>
Result<void,Error> SaveResult<Tree*>::save(Result<Tree*, Error> &result) {
    std::ofstream outFile;;

    outFile.open(file + FILE_FORMAT);

    if(outFile.is_open()) {
        if(!result.isSuccess()) {

            for(Error* error: result.getErrors()) {
                outFile << error->getErrorMessage() << std::endl;
            }
        }else {
            outFile << result.getValue()->printTree().getValue() << std::endl;
        }

        outFile.close();

        return Result<void,Error>::ok();
    }
    return Result<void,Error>::fail(new Error(NOT_OPEN));
}





#endif //SAVERESULT_H