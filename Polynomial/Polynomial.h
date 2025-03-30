#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "Collections/Vector.h"

class Term {
 private:
    int coefficient = 0;
    int degree = 1;

 public:
    Term();
    Term(int coefficient, int degree = 1);
    Term(const Term& term);

    ~Term();

    Term& operator=(Term term);
    Term& operator+=(const Term& term);

    Term operator+(const Term& term);

    friend std::ostream& operator<<(std::ostream& stream, Term& term);
    friend std::istream& operator>>(std::istream& stream, Term& term);

    friend class Polynomial;
};

class Polynomial {
 private:
    Vector<Term> poly;
    int degree = 1;

    bool order = false;

 public:
    Polynomial();
    Polynomial(int coefficient);
    Polynomial(const Term& term);
    Polynomial(const Polynomial& polynomial);

    ~Polynomial();

    Polynomial& operator=(const Polynomial& polynomial);
    Polynomial& operator+=(const Polynomial& polynomial);
    Polynomial& operator*=(const Polynomial& polynomial);

    friend Polynomial operator+(const Polynomial& firstPolynomial, const Polynomial& secondPolynomial);
    friend Polynomial operator*(const Polynomial& firstPolynomial, const Polynomial& secondPolynomial);

    friend std::ostream& operator<<(std::ostream& stream, const Polynomial& polynomial);
    friend std::istream& operator>>(std::istream& stream, Polynomial& polynomial);
};

#endif
