#include "Fraction.h"

#include <cmath>
#include <cstddef>
#include <string>
#include <iostream>
#include <sstream>

namespace {
const size_t kDecimalBase = 10;
const size_t kDecimalPlacesLenght = 4;

int FindGreatestCommonDivisor(int firstValue, int secondValue) {
    firstValue = std::abs(firstValue);
    secondValue = std::abs(secondValue);

    while (firstValue != 0 && secondValue != 0) {
        if (firstValue > secondValue) {
            firstValue = firstValue % secondValue;
        } else {
            secondValue = secondValue % firstValue;
        }
    }

    return firstValue + secondValue;
}

}  // namespace

void Fraction::Swap(Fraction& fraction) {
    std::swap(this->numerator, fraction.numerator);
    std::swap(this->denominator, fraction.denominator);
}

void Fraction::Simplify() {
    int greatestCommonDivisor = FindGreatestCommonDivisor(this->numerator, this->denominator);

    if (greatestCommonDivisor > 1) {
        this->numerator /= greatestCommonDivisor;
        this->denominator /= greatestCommonDivisor;
    }
}

Fraction::Fraction() = default;

Fraction::Fraction(int value) : numerator(value) {};

Fraction::Fraction(double value) : denominator(static_cast<int>(pow(kDecimalBase, kDecimalPlacesLenght))) {
    this->numerator = static_cast<int>(value * this->denominator);

    this->Simplify();
}

Fraction::Fraction(const char* value) {
    size_t sourceStringLength = strlen(value) + 1;
    char* sourceString = new char[sourceStringLength];
    strncpy(sourceString, value, sourceStringLength);

    int integerPart = 0;
    char* token = strtok(sourceString, " ");

    if (strcmp(token, sourceString) != 0) {
        std::istringstream integerPartStream(token);

        integerPartStream >> integerPart;
    }

    token = strtok(nullptr, "/");

    if (strcmp(token, sourceString) != 0) {
        std::istringstream numeratorPartStream(value);

        numeratorPartStream >> this->numerator;

        value = strtok(nullptr, "/");

        std::istringstream denominatorPartStream(value);

        denominatorPartStream >> this->denominator;
    }

    delete[] sourceString;

    this->numerator += (integerPart * this->denominator);

    this->Simplify();
}

Fraction::Fraction(const Fraction& fraction) = default;

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    this->Simplify();
}

Fraction& Fraction::operator=(Fraction fraction) {
    Swap(fraction);

    return *this;
}

Fraction::~Fraction() = default;

Fraction& Fraction::operator+=(const Fraction& fraction) {
    if (this->denominator == fraction.denominator) {
        this->numerator += fraction.numerator;
    } else {
        this->numerator += fraction.denominator * this->denominator;
        this->denominator *= fraction.denominator;
    }

    this->Simplify();

    return *this;
}

Fraction Fraction::operator+(const Fraction& fraction) {
    Fraction temp = *this;

    temp += fraction;

    return temp;
}

Fraction operator+(const int& value, const Fraction& fraction) {
    Fraction temp = fraction;

    temp += value;

    return temp;
}

Fraction operator+(const double& value, const Fraction& fraction) {
    Fraction temp = fraction;

    temp += value;

    return temp;
}

std::ostream& operator<<(std::ostream& stream, const Fraction& fraction) {
    if (fraction.numerator > fraction.denominator) {
        return stream << fraction.numerator / fraction.denominator << ' ' << fraction.numerator % fraction.denominator << '/' << fraction.denominator;
    } else {
        return stream << fraction.numerator << '/' << fraction.denominator;
    }
}

std::istream& operator>>(std::istream& stream, Fraction& fraction) {
    char buffer[256] {'\0'};

    std::getline(stream, buffer, '\n');

    Fraction inputFraction(buffer);

    fraction.Simplify();

    return stream;
}
