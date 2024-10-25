#ifndef NUMBER_H
#define NUMBER_H
#include <string>

#define INITIAL_LENGTH 1
#define POSITIVE 1
#define NEGATIVE 0

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
    int sign;

    int intLength(int value);
    void fillWith0s(int* table ,int length);
};



#endif //NUMBER_H
