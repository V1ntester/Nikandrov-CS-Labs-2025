#pragma once

#include <iostream>

class Fraction {
 private:
    int numerator = 0;
    int denominator = 1;

    void Swap(Fraction& fraction);

    void Simplify();

 public:
    Fraction();
    Fraction(int value);
    Fraction(double value);
    Fraction(const char* value);
    Fraction(const Fraction& fraction);
    Fraction(int numerator, int denominator);

    ~Fraction();

    Fraction& operator=(Fraction Fraction);

    Fraction& operator+=(const Fraction& fraction);

    Fraction operator+(const Fraction& fraction);
    friend Fraction operator+(const int& value, const Fraction& fraction);
    friend Fraction operator+(const double& value, const Fraction& fraction);

    friend std::ostream& operator<<(std::ostream& stream, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& stream, Fraction& fraction);
};
