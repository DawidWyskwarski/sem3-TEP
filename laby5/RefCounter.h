//
// Created by wyskw on 18.12.2024.
//

#ifndef REFCOUNTER_H
#define REFCOUNTER_H

class RefCounter
{
public:
    RefCounter() {}

    int add() {
        return ++count;
    }
    int dec() {
        return --count;
    }
    int get() const {
        return count;
    }
private:
    int count;
};

#endif //REFCOUNTER_H
