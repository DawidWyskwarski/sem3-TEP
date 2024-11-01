#include "Number.h"

#include <stdexcept>
#include <string>

Number::Number() {
    length = INITIAL_LENGTH;
    number = new int[length];
    number[0] = 0;
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

Number Number::operator+(const Number &other) {

    Number result;

    if (this->sign == other.sign) {

        result.sign = this->sign;

        delete[] result.number;
        result.number = add(this->number, other.number, this->length, other.length);
        result.length = std::max(this->length, other.length) + 1;
    }else {

        if( equalAbs(other.number,this->number,other.length,this->length) ) {
            return result;
        }

        delete[] result.number;

        if( bigger1abs(other.number,this->number,other.length,this->length) ){

            result.sign = other.sign;
            result.number = sub(other.number, this->number, other.length, this->length);
        }else {

            result.sign = this->sign;
            result.number = sub(this->number, other.number, this->length, other.length);
        }

        result.length = std::max(this->length, other.length);
    }

    result.trimLeading0s();
    return result;
}

Number Number::operator-(const Number &other) {
    Number result;

    if(*this == other) {
        return result;
    }

    if(&other == this) {
        return result;
    }

    if (this->sign != other.sign) {
        result.sign = this->sign;

        delete[] result.number;
        result.number = add(this->number, other.number, this->length, other.length);
        result.length = std::max(this->length, other.length) + 1;
    }else {

        delete[] result.number;

        if (bigger1abs(this->number, other.number, this->length, other.length)) {
            result.sign = this->sign;
            result.number = sub(this->number, other.number, this->length, other.length);
        } else {
            result.sign = -this->sign;
            result.number = sub(other.number, this->number, other.length, this->length);
        }

        result.length = std::max(this->length, other.length);
    }

    result.trimLeading0s();
    return result;

}

Number Number::operator*(const Number &other) {
    Number result;

    if(other.length == 1 && other.number[0] == 0) {
        return result;
    }
    if(this->length == 1 && this->number[0] == 0) {
        return result;
    }

    const int rows = other.length;
    const int cols = this->length + rows;

    result.sign = this->sign * other.sign;
    result.length = cols;

    delete[] result.number;
    result.number = new int[cols];

    fillWith0s(result.number, cols);

    for (int i = 0; i < rows; ++i) {
        int carry = 0;
        for (int j = 0; j < this->length; ++j) {
            int pos = cols - 1 - (i + j);
            int mul = other.number[rows - 1 - i] * this->number[this->length - 1 - j] + result.number[pos] + carry;

            result.number[pos] = mul % 10;
            carry = mul / 10;
        }
        result.number[cols - 1 - (i + this->length)] += carry;
    }

    result.trimLeading0s();
    return result;
}

Number Number::operator/(const Number &other) {

    if(other.length == 1 && other.number[0] == 0) {
        throw std::invalid_argument( "Error. Can't divide by 0" );
    }
    Number result;

    if(*this < other) {
        return result;
    }
    if(this->length == 1 && this->number[0] == 0) {
        return result;
    }

    result.length = this->length;
    result.sign = this->sign * other.sign;

    delete[] result.number;
    result.number = new int[result.length];
    fillWith0s(result.number,result.length);

    int* dividend = new int[this->length];

    for(int i=0;i<this->length;++i) {
        if(i < this->length) {
            dividend[i] = this->number[i];
        }else {
            dividend[i] = 0;
        }
    }

    int* divisor = new int[this->length];

    for(int i=0;i<this->length;++i) {
        if(i < other.length) {
            divisor[i] = other.number[i];
        }else {

            divisor[i] = 0;
        }
    }

    for(int i = 0; i < this->length; ++i) {

        while(! bigger1abs(divisor,dividend,this->length,this->length) ) {
            result.number[i]++;
            int* tmp = sub(dividend,divisor,this->length,this->length);

            for(int j = 0; j < this->length; ++j) {
                dividend[j] = tmp[j];
            }
            delete[] tmp;
        }

        for(int j = this->length-1;j>0;--j) {
            divisor[j] = divisor[j-1];
        }
        divisor[0] = 0;

    }

    result.trimLeading0s();
    delete[] divisor;
    delete[] dividend;
    return result;
}

bool Number::operator>(const Number &other) {
    if(this->sign > other.sign) {
        return true;
    }
    if(this->sign < other.sign) {
        return false;
    }

    if(this->sign == POSITIVE) {
        return bigger1abs(this->number, other.number, this->length, other.length);
    }

    return bigger1abs(other.number, this->number, other.length, this->length);
}
bool Number::operator<(const Number &other) {
    return !(*this>other) && *this!=other;
}

bool Number::operator==(const Number &other) {
    if (this->sign != other.sign) {
        return false;
    }
    return equalAbs(this->number, other.number, this->length, other.length);
}
bool Number::operator!=(const Number &other) {
    return !(*this == other);
}

bool Number::operator>=(const Number &other) {
    return *this > other || *this == other;
}
bool Number::operator<=(const Number &other) {
    return *this < other || *this == other;
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

int* Number::add(const int *number1, const int *number2,const  int len1,const  int len2) {

    const int resultLen = std::max(len1, len2) + 1;
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

int* Number::sub(const int *number1, const int *number2,const int len1,const int len2) {

    //number1 is always bigger than number2
    int resultLen = std::max(len1, len2);
    int* result = new int[resultLen];

    fillWith0s(result, resultLen);

    bool carry = false;

    for(int i = 0; i < resultLen; ++i) {

        int diff = number1[len1 -1 - i] - carry;

        if (i < len2) {
            diff -= number2[len2 - 1 - i];
        }

        if (diff<0) {
            diff+=10;
            carry = true;
        }else {
            carry = false;
        }

        result[resultLen-1-i] = diff;
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

void Number::fillWith0s(int *table,const int length) {
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

bool Number::bigger1abs(const int *number1, const int *number2,const int len1,const int len2) {
    if(len1 > len2) {
        return true;
    }
    if(len2 > len1 ) {
        return false;
    }

    for(int i=0;i<len1;i++) {
        if(number1[i] > number2[i]) {
            return true;
        }

        if(number1[i] < number2[i]) {
            return false;
        }
    }

    return false;
}

bool Number::equalAbs(const int *number1, const int *number2,const int len1,const int len2) {
    if (len1 != len2) {
        return false;
    }

    for(int i=0;i<len1;++i) {
        if(number1[i] != number2[i]) {
            return false;
        }
    }
    return true;
}