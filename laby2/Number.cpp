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

void Number::operator=(const Number &other) {
    if (this != &other) {
        delete[] number;

        sign = other.sign;
        length = other.length;
        number = new int[other.length];

        for (int i=length-1; i>=0; i--) {
            number[i] = other.number[i];
        }
    }
}

Number Number::operator+(Number &other) {

    Number result;

    if (this->sign == POSITIVE && other.sign == POSITIVE) {
        result.sign = POSITIVE;
        result.number = add(this->number, other.number, this->length, other.length);
        result.length = std::max(this->length, other.length) + 1;
    }

    if (this->sign == NEGATIVE && other.sign == NEGATIVE) {
        result.sign = NEGATIVE;
        result.number = add(this->number, other.number, this->length, other.length);
        result.length = std::max(this->length, other.length) + (result.number[0] != 0);
    }

    result.trimLeading0s();
    return result;
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

int* Number::add(const int *number1,const int *number2, int len1, int len2) {

    int resultLen = std::max(len1, len2) + 1;
    int* result = new int[resultLen];

    fillWith0s(result, resultLen);

    int carry = 0;

    for (int i = 0; i < resultLen - 1; ++i) {

        int sum = carry;
        if (i < len1) {
            sum += number1[len1 - 1 - i];
        }
        if (i < len2) {
            sum += number2[len2 - 1 - i];
        }

        result[resultLen - 1 - i] = sum % 10;
        carry = sum / 10;
    }

    result[0] = carry;

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

void Number::trimLeading0s() {

    int count0s = 0;

    while (count0s < length-1 && number[count0s] == 0) {
        ++count0s;
    }

    if (count0s != 0) {
        int newLength = length - count0s;
        int* trimmedResult = new int[newLength];

        for (int i = 0; i < newLength; ++i) {
            trimmedResult[i] = number[i + count0s];
        }

        delete[] number;
        number = trimmedResult;
        length = newLength;
    }
}

