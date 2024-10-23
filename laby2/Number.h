#ifndef NUMBER_H
#define NUMBER_H
#include <string>

const int initialLength = 3;

class Number {

public:
    Number();
    ~Number();

    void operator=(int value);
    void operator=(Number &number);
    Number operator+(Number &number);
    Number operator-(Number &number);
    Number operator*(Number &number);
    Number operator/(Number &number);

    std::string toStr();

private:
    int* number;
    int length;

    int intLength(int value);
};



#endif //NUMBER_H
