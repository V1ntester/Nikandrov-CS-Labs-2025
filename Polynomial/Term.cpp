#include "Polynomial.h"

#include <cstddef>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {
const size_t kStringBufferSize = 256;
}

Term::Term() = default;

Term::Term(int coefficient, int degree) : coefficient(coefficient), degree(degree) {};

Term::Term(const Term& term) = default;

Term::~Term() = default;

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

Term& Term::operator*=(const Term& term) {
    this->coefficient *= term.coefficient;
    this->degree += term.degree;

    return *this;
}

Term Term::operator+(const Term& term) {
    Term temp = *this;

    temp += term;

    return temp;
}

Term Term::operator*(const Term& term) {
    Term temp = *this;

    temp *= term;

    return temp;
}

bool Term::operator<(const Term& term) const {
    if (this->degree == term.degree) {
        return this->coefficient < term.coefficient;
    }

    return this->degree < term.degree;
}

bool Term::operator>(const Term& term) const {
    return term < *this;
}

std::ostream& operator<<(std::ostream& stream, Term term) {
    if (term.coefficient < 0) {
        stream << "- ";
    }

    if (term.coefficient != 0 && term.coefficient != 1 || term.degree == 0) {
        stream << std::abs(term.coefficient);
    }

    if (term.degree == 1) {
        stream << 'x';
    } else if (term.degree != 0) {
        stream << "x^" << term.degree;
    }

    return stream;
}

std::istream& operator>>(std::istream& stream, Term& term) {
    char stringBuffer[kStringBufferSize]{'\0'};
    char stringSourceValue[kStringBufferSize]{'\0'};

    stream >> stringBuffer;

    strncpy(stringSourceValue, stringBuffer, kStringBufferSize);

    if (stringSourceValue[0] == 'x' && stringSourceValue[1] == '\0' ||
        stringSourceValue[0] == '+' && stringSourceValue[1] == 'x' && stringSourceValue[2] == '\0') {
        term.coefficient = 1;
        term.degree = 1;
    } else if (stringSourceValue[0] == '-' && stringSourceValue[1] == 'x' && stringSourceValue[2] == '\0') {
        term.coefficient = -1;
        term.degree = 1;
    } else if (stringSourceValue[0] == 'x' && stringSourceValue[1] == '^') {
        term.coefficient = 1;

        char* token = strtok(stringBuffer, "x^");

        std::istringstream stringStream(token);

        stringStream >> term.degree;
    } else if (stringSourceValue[0] == '+' && stringSourceValue[1] == 'x' && stringSourceValue[2] == '^') {
        term.coefficient = 1;

        char* token = strtok(stringBuffer, "+x^");

        std::istringstream stringStream(token);

        stringStream >> term.degree;
    } else if (stringSourceValue[0] == '-' && stringSourceValue[1] == 'x' && stringSourceValue[2] == '^') {
        term.coefficient = -1;

        char* token = strtok(stringBuffer, "-x^");

        std::istringstream stringStream(token);

        stringStream >> term.degree;
    } else if (stringSourceValue[strlen(stringSourceValue) - 1] == 'x' && stringSourceValue[strlen(stringSourceValue)] == '\0') {
        char* token = strtok(stringBuffer, "x");

        std::istringstream stringStream(token);

        stringStream >> term.coefficient;

        term.degree = 1;
    } else {
        char* token = strtok(stringBuffer, "x^");

        std::istringstream stringStream(token);

        stringStream >> term.coefficient;

        if (strcmp(stringBuffer, stringSourceValue) != 0) {
            token = strtok(nullptr, "x^");

            stringStream.clear();
            stringStream.str(token);

            stringStream >> term.degree;
        }
    }

    return stream;
}
