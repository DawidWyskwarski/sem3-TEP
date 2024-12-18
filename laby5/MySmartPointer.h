    //
    // Created by wyskw on 18.12.2024.
    //

    #ifndef MYSMARTPOINTER_H
    #define MYSMARTPOINTER_H

    #include "RefCounter.h"

    template <typename T>
    class MySmartPointer
    {
    public:
        MySmartPointer(T *point)
        {
            pointer = point;
            counter = new RefCounter();
            counter -> add();
        }
        MySmartPointer(const MySmartPointer &other)
        {
            pointer = other.pointer;
            counter = other.counter;
            counter -> add();
        }
        ~MySmartPointer(){

            if (counter->dec() == 0){
                delete pointer;
                delete counter;
            }
        }

        MySmartPointer& operator=(const MySmartPointer& other) {
            if(*this == other) {
                return *this;
            }

            if (counter->dec() == 0){
                delete pointer;
                delete counter;
            }

            pointer = other.pointer;
            counter = other.counter;

            counter -> add();

            return *this;
        }

        T& operator*() {
            return *pointer;
        }

        T* operator->() {
            return pointer;
        }
    private:
        RefCounter *counter;
        T *pointer;
    };

    #endif //MYSMARTPOINTER_H
