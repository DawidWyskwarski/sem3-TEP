#include "Number.h"
#include <string>

Number::Number() {
    length = INITIAL_LENGTH;
    number = new int[length];
    sign = POSITIVE;
}

Number::~Number() {
    delete[] number;
}

void Number::operator=(int value) {
    int newLength = intLength(value);

    int* newNumber = new int[newLength];

    if(value < 0) {
        sign = NEGATIVE;
        value = -value;
    }

    for (int i = newLength-1; i >=0 ; --i) {
        newNumber[i] = value%10;
        value/=10;
    }

    delete[] number;
    number = newNumber;
    length = newLength;
}

void Number::operator=(Number &other) {
    if (this != &other) {
        delete[] number;

        number = new int[other.length];
        sign = other.sign;
        length = other.length;

        for (int i=length-1; i>=0; i--) {
            number[i] = other.number[i];
        }
    }
}

Number Number::operator+(Number &other) {
}

Number Number::operator-(Number &other) {
}

Number Number::operator*(Number &other) {
}

Number Number::operator/(Number &other) {
}

std::string Number::toStr() {
    std::string result;

    for (int i = length-1; i >= 0; --i) {
        switch (number[i]) {
            case 0:
                result = '0' + result;
                break;
            case 1:
                result = '1' + result;
                break;
            case 2:
                result = '2' + result;
                break;
            case 3:
                result = '3' + result ;
                break;
            case 4:
                result = '4' + result;
                break;
            case 5:
                result = '5' + result;
                break;
            case 6:
                result = '6' + result;
                break;
            case 7:
                result = '7' + result;
                break;
            case 8:
                result = '8' + result;
                break;
            case 9:
                result = '9' + result;
                break;
        }
    }

    if(sign == NEGATIVE) {
        result = "-" + result;
    }

    return result;
}

int Number::intLength(int value) {
    if (value == 0) {
        return 1;
    }
    int length = 0;

    if (value < 0) {
        value*=-1;
    }

    while (value != 0) {
        length++;
        value /= 10;
    }
    return length;
}

void Number::fillWith0s(int *table, int length) {
    for(int i=0;i<length;++i) {
        table[i] = 0;
    }
}
