#pragma once

#include <iostream>
#include "Collections/Vector.h"

class Polynomial;

class Term {
 private:
    int coefficient = 0;
    int degree = 0;

 public:
    Term();
    Term(int coefficient, int degree = 0);
    Term(const Term& term);

    ~Term();

    Term& operator=(Term term);
    Term& operator+=(const Term& term);
    Term& operator*=(const Term& term);

    Term operator+(const Term& term);
    Term operator*(const Term& term);

    bool operator<(const Term& term) const;
    bool operator>(const Term& term) const;

    friend std::ostream& operator<<(std::ostream& stream, Term term);
    friend std::istream& operator>>(std::istream& stream, Term& term);

    friend class Polynomial;
    friend std::ostream& operator<<(std::ostream& stream, Polynomial polynomial);
    friend std::istream& operator>>(std::istream& stream, Polynomial& polynomial);
};

class Polynomial {
 private:
    Vector<Term> poly;
    int degree = 0;

    bool orderReverse = false;

    void Add(const Term& term);
   
    void UpdateDegree();
    void Sort();
    void Simplify();

 public:
    Polynomial();
    Polynomial(bool order);
    Polynomial(int coefficient);
    Polynomial(const Term& term);
    Polynomial(const Polynomial& polynomial);

    ~Polynomial();

    Polynomial& operator=(Polynomial polynomial);
    Polynomial& operator+=(Polynomial& polynomial);
    Polynomial& operator*=(Polynomial& polynomial);

    friend Polynomial operator+(Polynomial& firstPolynomial, Polynomial& secondPolynomial);
    friend Polynomial operator*(Polynomial& firstPolynomial, Polynomial& secondPolynomial);

    friend std::ostream& operator<<(std::ostream& stream, Polynomial polynomial);
    friend std::istream& operator>>(std::istream& stream, Polynomial& polynomial);
};
