#include "Polynomial.h"

#include <stdexcept>
#include <iostream>

Term::Term() = default;

Term::Term(int coefficient, int degree) : coefficient(coefficient), degree(degree) {};

Term::Term(const Term& term) {
    this->coefficient = term.coefficient;
    this->degree = term.degree;
}

Term::~Term() {};

Term& Term::operator=(Term term) {
    std::swap(this->coefficient, term.coefficient);
    std::swap(this->degree, term.degree);

    return *this;
}

Term& Term::operator+=(const Term& term) {
    try {
        if (this->degree != term.degree) {
            throw std::invalid_argument("Trying to sum different degrees");
        }
    } catch (const std::invalid_argument& exception) {
        std::cout << exception.what() << '\n';
    }

    this->coefficient += term.coefficient;

    return *this;
}

Term Term::operator+(const Term& term) {
    Term temp = *this;

    temp += term;

    return temp;
}

std::ostream& operator<<(std::ostream& stream, const Term& term) {
    
}
