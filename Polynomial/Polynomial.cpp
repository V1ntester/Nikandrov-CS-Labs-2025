#include "Polynomial.h"

#include <cstddef>
#include <iostream>
#include <sstream>

namespace {
const size_t kStringBufferSize = 256;
}

void Polynomial::Add(const Term& term) {
    this->poly.Add(term);

    if (this->degree < term.degree) {
        this->degree = term.degree;
    }
}

void Polynomial::UpdateDegree() {
    size_t polyLength = this->poly.GetLength();

    if (polyLength == 0) {
        this->degree = 0;

        return;
    }

    int maxDegree = this->poly[0].degree;

    for (size_t i = 1; i < polyLength; i++) {
        if (maxDegree < this->poly[i].degree) {
            maxDegree = this->poly[i].degree;
        }
    }

    this->degree = maxDegree;
}

void Polynomial::Sort() {
    size_t polyLength = this->poly.GetLength();

    for (size_t i = 0; i < polyLength; i++) {
        bool isSwaped = false;

        for (size_t j = 0; j < polyLength - 1; j++) {
            if (!orderReverse) {
                if (this->poly[j] < this->poly[j + 1]) {
                    std::swap(this->poly[j], this->poly[j + 1]);

                    isSwaped = true;
                }
            } else {
                if (this->poly[j] > this->poly[j + 1]) {
                    std::swap(this->poly[j], this->poly[j + 1]);

                    isSwaped = true;
                }
            }
        }

        if (!isSwaped) {
            break;
        }
    }
}

void Polynomial::Simplify() {
    if (this->poly.GetLength() == 0) {
        return;
    }

    this->Sort();

    for (size_t i = 1; i < this->poly.GetLength(); i++) {
        if (this->poly[i - 1].degree != this->poly[i].degree) {
            continue;
        }

        this->poly[i - 1].coefficient += this->poly[i].coefficient;

        this->poly.Delete(i);

        if(this->poly[i - 1].coefficient == 0) {
            this->poly.Delete(i - 1);
        }

        --i;
    }

    this->UpdateDegree();
}

Polynomial::Polynomial() = default;

Polynomial::Polynomial(bool orderReverse) : orderReverse(orderReverse) {
}

Polynomial::Polynomial(int coefficient) {
    Term term(coefficient);

    this->Add(term);
}

Polynomial::Polynomial(const Term& term) : degree(term.degree) {
    this->Add(term);
}

Polynomial::Polynomial(const Polynomial& polynomial) = default;

Polynomial::~Polynomial() = default;

Polynomial& Polynomial::operator=(Polynomial polynomial) {
    std::swap(this->poly, polynomial.poly);
    std::swap(this->degree, polynomial.degree);

    return *this;
}

Polynomial& Polynomial::operator+=(Polynomial& polynomial) {
    size_t polyLength = polynomial.poly.GetLength();

    for (size_t i = 0; i < polyLength; i++) {
        this->Add(polynomial.poly[i]);
    }

    this->Simplify();

    return *this;
}

Polynomial& Polynomial::operator*=(Polynomial& polynomial) {
    size_t firstPolyLength = this->poly.GetLength();
    size_t secondPolyLength = polynomial.poly.GetLength();

    Polynomial newPolynomial;

    for (size_t i = 0; i < firstPolyLength; i++) {
        for (size_t j = 0; j < secondPolyLength; j++) {
            newPolynomial.Add(this->poly[i] * polynomial.poly[j]);
        }
    }

    newPolynomial.Simplify();

    *this = newPolynomial;

    return *this;
}

Polynomial operator+(Polynomial& firstPolynomial, Polynomial& secondPolynomial) {
    Polynomial temp = firstPolynomial;

    temp += secondPolynomial;

    return temp;
}

Polynomial operator*(Polynomial& firstPolynomial, Polynomial& secondPolynomial) {
    Polynomial temp = firstPolynomial;

    temp *= secondPolynomial;

    return temp;
}

std::ostream& operator<<(std::ostream& stream, Polynomial polynomial) {
    size_t polyLength = polynomial.poly.GetLength();

    if (polyLength == 0) {
        stream << '0';

        return stream;
    }

    stream << polynomial.poly[0] << ' ';

    for (size_t i = 1; i < polyLength; i++) {
        if (polynomial.poly[i].coefficient > 0) {
            stream << "+ ";
        }

        stream << polynomial.poly[i] << ' ';
    }

    return stream;
}

std::istream& operator>>(std::istream& stream, Polynomial& polynomial) {
    char stringBuffer[kStringBufferSize]{'\0'};

    stream.getline(stringBuffer, kStringBufferSize);

    for (size_t i = 0; i < kStringBufferSize - 1; i++) {
        if (stringBuffer[i] == ' ' && (stringBuffer[i + 1] != '-' && stringBuffer[i + 1] != '+')) {
            for (size_t j = i; j < kStringBufferSize; j++) {
                std::swap(stringBuffer[j], stringBuffer[j + 1]);
            }

            stringBuffer[kStringBufferSize - 1] = '\0';

            --i;
        }
    }

    size_t termsCount = (stringBuffer[0] != '\0' && stringBuffer[0] != ' ' ? 1 : 0);
    std::istringstream stringStream(stringBuffer);

    for (size_t i = 0; i < strlen(stringBuffer); i++) {
        if (stringBuffer[i] == ' ') {
            ++termsCount;
        }
    }

    for (size_t i = 0; i < termsCount; i++) {
        Term term;

        stringStream >> term;

        if (term.coefficient != 0) {
            polynomial.Add(term);
        }
    }

    polynomial.Simplify();

    return stream;
}
