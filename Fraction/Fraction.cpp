#include "Fraction.h";

#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cmath>

namespace {
const size_t kDecimalBase = 10;
const size_t kDecimalPlacesLenght = 4;

int FindGreatestCommonDivisor(int firstValue, int secondValue) {

    while(firstValue != 0 && secondValue != 0) {
        if (firstValue > secondValue) {
            firstValue = firstValue % secondValue;
        } else {
            secondValue = secondValue % firstValue;
        }
    }

    return firstValue + secondValue;
}

}  // namespace

void Fraction::Simplify() {
    int greatestCommonDivisor = FindGreatestCommonDivisor(this->numerator, this->denominator);

    if (greatestCommonDivisor > 1) {
        this->numerator/=greatestCommonDivisor;
        this->denominator/=greatestCommonDivisor;
    }
}

Fraction::Fraction() = default;

Fraction::Fraction(int value) : numerator(value) {};

Fraction::Fraction(char* value) {
    char* string = value;
    string = strtok(string, "/");

    sscanf(string, "%d", &this->numerator);

    string = strtok(string, "/");

    sscanf(string, "%d", &this->denominator);
}

Fraction::Fraction(double value) {
    this->denominator = pow(kDecimalBase, kDecimalPlacesLenght);
    this->numerator = value * this->denominator;

    this->Simplify();
}

Fraction& Fraction::operator+=(const Fraction& fraction) {
    
}

Fraction Fraction::operator+(const Fraction& fraction) {
    
}
