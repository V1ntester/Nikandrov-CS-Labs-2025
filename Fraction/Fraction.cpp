#include "Fraction.h"

#include <cmath>
#include <cstddef>
#include <cstring>
#include <exception>
#include <iostream>
#include <sstream>

namespace {
const size_t kDecimalBase = 10;
const size_t kDecimalPlacesLenght = 4;

const size_t kBufferSize = 256;

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
    if (this->numerator < 0 && this->denominator < 0) {
        this->numerator *= (-1);
        this->denominator *= (-1);
    }

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

    int integer = 0;
    int numerator = 0;
    int denominator = 1;
    char delimiter = '\0';

    try {
        std::istringstream stream(value);

        char* token = strtok(sourceString, " ");

        if (strcmp(token, value) == 0) {
            stream >> integer;

            if (stream >> delimiter && delimiter == '/') {
                std::swap(numerator, integer);

                stream >> denominator;
            }
        } else {
            stream >> integer;
            stream >> numerator;
            stream >> delimiter;
            stream >> denominator;
        }

        delete[] sourceString;

        if (denominator == 0) {
            throw std::invalid_argument("Invalid denominator");
        }

    } catch (const std::invalid_argument& exception) {
        std::cout << exception.what() << '\n';

        this->numerator = 0;
        this->denominator = 0;

        return;
    }

    this->numerator = integer < 0 ? numerator * (-1) : numerator;
    this->denominator = denominator;
    this->numerator += (integer * denominator);

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
        this->numerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
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
    if (std::abs(fraction.numerator) >= std::abs(fraction.denominator)) {
        stream << fraction.numerator / fraction.denominator << ' ';

        if (std::abs(fraction.numerator) % std::abs(fraction.denominator) != 0) {
            fraction.numerator != 0 ? stream << std::abs(fraction.numerator) % std::abs(fraction.denominator) << '/' << std::abs(fraction.denominator)
                                    : stream << 0;
        }
    } else {
        fraction.numerator != 0 ? stream << fraction.numerator << '/' << fraction.denominator : stream << 0;
    }

    return stream;
}

std::istream& operator>>(std::istream& stream, Fraction& fraction) {
    char buffer[kBufferSize]{'\0'};

    stream.getline(buffer, kBufferSize);

    fraction = buffer;

    return stream;
}
