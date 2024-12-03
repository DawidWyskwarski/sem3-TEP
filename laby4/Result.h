//
// Created by wyskw on 29.11.2024.
//

#ifndef RESULT_H
#define RESULT_H
#include <vector>


template <typename T, typename E>
class Result {
public:
    Result(const T& val);
    Result(E* error);
    Result(std::vector<E*> err);
    Result(const Result<T,E>& other);

    ~Result();

    static Result<T,E> ok(const T& val);
    static Result<T,E> fail(E* err);
    static Result<T,E> fail(std::vector<E*>& err);

    Result<T,E>& operator=(Result<T,E> other);

    bool isSuccess();

    T getValue();

    std::vector<E*>& getErrors();

private:
    T* value;
    std::vector<E*> errors;
};

template<typename T, typename E>
Result<T, E>::Result(const T &val):value(new T(val)) {}

template<typename T, typename E>
Result<T, E>::Result(E *error):value(nullptr) { errors.push_back(error); }

template<typename T, typename E>
Result<T, E>::Result(std::vector<E *> err):value(nullptr) { errors = err; }

template<typename T, typename E>
Result<T, E>::Result(const Result<T, E>& other)
:value(other.value ? new T(*other.value) : nullptr) {
    for(int i=0;i<other.errors.size();++i) {
        errors.push_back(new E( *other.errors[i] ));
    }
}


template<typename T, typename E>
Result<T, E>::~Result() {

    delete value;

    for(int i=0;i<errors.size();++i) {
        delete errors[i];
    }
}


template<typename T, typename E>
Result<T, E> Result<T, E>::ok(const T &val) {
    return Result(val);
}

template<typename T, typename E>
Result<T, E> Result<T, E>::fail(E *err) {
    return Result(err);
}

template<typename T, typename E>
Result<T, E> Result<T, E>::fail(std::vector<E *> &err) {
    return Result(err);
}


template<typename T, typename E>
Result<T, E> &Result<T, E>::operator=(Result<T, E> other) {
    if (this==&other) return *this;

    std::swap(value,other.value);
    std::swap(errors,other.errors);

    return *this;
}


template<typename T, typename E>
bool Result<T, E>::isSuccess() {
    return value != nullptr && errors.empty();
}


template<typename T, typename E>
std::vector<E *> &Result<T, E>::getErrors() { return errors; }

template<typename T, typename E>
T Result<T, E>::getValue() {

    return *value;
}


template<typename E>
class Result<void,E> {
public:
    Result();
    Result(E *error);
    Result(std::vector<E*>& err);
    Result(const Result<void, E>& other);

    ~Result();

    static Result<void, E> ok();
    static Result<void, E> fail(E* error);
    static Result<void, E> fail(std::vector<E*>& err);

    Result<void, E>& operator=(Result<void, E> other);

    bool isSuccess();

    std::vector<E*>& getErrors();

private:
    std::vector<E*> errors;
};

template<typename E>
Result<void, E>::Result() {}

template<typename E>
Result<void, E>::Result(E *error) {
    errors.push_back(error);
}

template<typename E>
Result<void, E>::Result(std::vector<E *> &err) {
    errors = err;
}

template<typename E>
Result<void, E>::Result(const Result<void, E> &other) {

    for(int i=0;i<other.errors.size();++i) {
        errors.push_back(new E( *other.errors[i] ));
    }
}


template<typename E>
Result<void, E>::~Result() {
    for(int i=0;i<errors.size();++i) {
        delete errors[i];
    }
    errors.clear();
}

template<typename E>
Result<void, E> Result<void, E>::ok() {
    return Result();
}

template<typename E>
Result<void, E> Result<void, E>::fail(E *error) {
    return Result(error);
}

template<typename E>
Result<void, E> Result<void, E>::fail(std::vector<E *> &err) {
    return Result(err);
}

template<typename E>
Result<void, E> &Result<void, E>::operator=(Result<void, E> other) {
    if (this==&other) return *this;

    std::swap(errors,other.errors);

    return *this;
}

template<typename E>
bool Result<void, E>::isSuccess() {
    return errors.empty();
}

template<typename E>
std::vector<E *> &Result<void, E>::getErrors() {
    return errors;
}


#endif //RESULT_H
