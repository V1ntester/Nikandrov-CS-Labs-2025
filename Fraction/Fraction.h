#pragma once

class Fraction {
 private:
    int numerator = 0;
    int denominator = 1;

    void Simplify();

 public:
    Fraction();
    Fraction(int value);
    Fraction(char* string);
    Fraction(double value);
    Fraction(const Fraction& fraction);
    Fraction(int numerator, int denominator);

    ~Fraction();

    Fraction& operator+=(const Fraction& fraction);
    Fraction& operator-=(const Fraction& fraction);
    Fraction& operator*=(const Fraction& fraction);
    Fraction& operator/=(const Fraction& fraction);

    Fraction operator+(const Fraction& fraction);
    Fraction operator-(const Fraction& fraction);
    Fraction operator*(const Fraction& fraction);
    Fraction operator/(const Fraction& fraction);

    // int GetNumerator() const;
    // int GetDenominator() const;

    // void SetNumerator(int numerator);
    // void SetDenominator(int denominator);
};
