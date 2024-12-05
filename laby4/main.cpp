#include <iostream>

#include "ConsoleUserInterface.h"
#include "Result.h"
#include "Error.h"
#include "SaveResult.h"
#include "Tree.h"

void testSaveResultWithErrors() {
    Error* error1 = new Error("Error 1 occurred");
    Error* error2 = new Error("Error 2 occurred");

    std::vector<Error*> errors = {error1, error2};
    Result<int, Error> resultWithErrors = Result<int, Error>::fail(errors);

    SaveResult<int> saver("test_result_errors");
    saver.save(resultWithErrors);
}

void testSaveResultWithSuccess() {
    Result<int, Error> resultSuccess = Result<int, Error>::ok(42);

    SaveResult<int> saver("test_result_success");
    saver.save(resultSuccess);
}

void testSaveResultWithTree() {

    Tree tree;
    std::string formula = "+ 1 2";
    tree.buildTree(formula);

    Result<Tree*, Error> resultWithTree = Result<Tree*, Error>::ok(&tree);

    SaveResult<Tree*> treeSaver("test_result_tree");
    treeSaver.save(resultWithTree);
}

void testSaveResultWithTreeErrors() {
    Error* error = new Error("odwaliles Tree error occurred");
    Result<Tree*, Error> resultWithErrors = Result<Tree*, Error>::fail(error);

    SaveResult<Tree*> treeSaver("test_result_tree_errors");
    treeSaver.save(resultWithErrors);
}

int main() {

    //ConsoleUserInterface cui;
    //cui.startSession();

    testSaveResultWithErrors();
    testSaveResultWithSuccess();
    testSaveResultWithTree();
    testSaveResultWithTreeErrors();

    return 0;
}
