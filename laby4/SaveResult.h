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

template<typename T>
class SaveResult {
public:
    SaveResult();
    SaveResult(const std::string& file);

    void save(Result<T,Error>& result);

private:
    std::string file;
};

template<typename T>
SaveResult<T>::SaveResult():file("result") {}

template<typename T>
SaveResult<T>::SaveResult(const std::string &file):file(file) {};

template<typename T>
void SaveResult<T>::save(Result<T, Error> &result) {
    std::ofstream outFile;;

    outFile.open(file + ".txt");

    if(outFile.is_open()) {
        if(!result.isSuccess()) {
            for(Error* error: result.getErrors()) {
                outFile << error->getErrorMessage() << std::endl;
            }
        }
    }
    outFile.close();
}

template<>
void SaveResult<Tree*>::save(Result<Tree*, Error> &result) {
    std::ofstream outFile;;

    outFile.open(file + ".txt");

    if(outFile.is_open()) {
        if(!result.isSuccess()) {

            for(Error* error: result.getErrors()) {
                outFile << error->getErrorMessage() << std::endl;
            }
        }else {
            outFile << result.getValue()->printTree().getValue() << std::endl;
        }
    }
    outFile.close();
}





#endif //SAVERESULT_H