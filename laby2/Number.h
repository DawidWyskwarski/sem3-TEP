#ifndef NUMBER_H
#define NUMBER_H
#include <string>

#define INITIAL_LENGTH 1
#define POSITIVE 1
#define NEGATIVE (-1)
#define BASE10 10
#define ERROR_DIVIDE_0 "Error. Can't divide by 0"

class Number {

public:
    Number();
    Number(const Number &other);
    ~Number();

    void operator=(int value);
    void operator=(const Number &other);
    Number operator+(const Number &other);
    Number operator-(const Number &other);
    Number operator*(const Number &other);
    Number operator/(const Number &other);

    bool operator>(const Number &other);
    bool operator<(const Number &other);
    bool operator==(const Number &other);
    bool operator!=(const Number &other);
    bool operator>=(const Number &other);
    bool operator<=(const Number &other);

    std::string toStr();

private:
    int* number;
    int length;
    int sign;

    int intLength(int value);
    void fillWith0s(int* table ,int length);
    int* add(const int* number1,const int* number2,int len1, int len2);
    int* sub(const int* number1,const int* number2, int len1, int len2);
    bool bigger1abs(const int* number1,const int* number2, int len1, int len2);
    bool equalAbs(const int* number1,const int* number2, int len1, int len2);
    void trimLeading0s();
};



#endif //NUMBER_H
