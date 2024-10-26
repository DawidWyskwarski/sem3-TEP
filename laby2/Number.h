#ifndef NUMBER_H
#define NUMBER_H
#include <string>

#define INITIAL_LENGTH 1
#define POSITIVE 1
#define NEGATIVE (-1)

class Number {

public:
    Number();
    ~Number();

    void operator=(int value);
    void operator=(const Number &number);
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
    int* add(const int* number1,const int* number2, int len1, int len2);
    void trimLeading0s();
};



#endif //NUMBER_H
