//
// Created by wyskw on 13.01.2025.
//

#ifndef UNIQUEPOINTER_H
#define UNIQUEPOINTER_H

template <typename T>
class UniquePointer
{
public:

    UniquePointer(T* point) {
        pointer = point;
    }

    UniquePointer(const UniquePointer& other) = delete;

    UniquePointer(UniquePointer&& other) noexcept {
        pointer = other.pointer;
        other.pointer = nullptr;
    }

    ~UniquePointer() {
        delete pointer;
    }

    UniquePointer& operator=(const UniquePointer& other) = delete;

    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if(&other == this) {
            return *this;
        }

        delete pointer;
        pointer = other.pointer;

        other.pointer = nullptr;

        return *this;
    }

    T& operator*() {
        return *pointer;
    }

    T* operator->() {
        return pointer;
    }

private:
    T* pointer;
};

#endif //UNIQUEPOINTER_H
