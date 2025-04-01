#include "Handler.h"

#include <iostream>
#include "Polynomial/Polynomial.h"

void Handler::InteractiveModeInit() {
    // Term term;

    // std::cout << "Введите терм: ";
    // std::cin >> term;

    // std::cout << "Ваш терм: " << term << '\n';
    // std::cout << "Сумма двух термов: " << (term + term) << '\n';
    // std::cout << "Терм в квадрате: " << (term * term) << '\n';

    // std::cout << '\n';

    // std::cin.ignore();

    Polynomial firstPolynomial;
    Polynomial secondPolynomial;

    // Examples for test: 3x^2 - x^2 -    3x^2 + x ^2 + 5x^5   - 4x^3 +x^2 - 7
    // -1x + 0x^6 -1x^6 +x^6 + x      
    // -0 +0 -0x^0 +1x^1
    std::cout << "Введите первый полином: ";
    std::cin >> firstPolynomial;

    std::cout << "Введите второй полином: ";
    std::cin >> secondPolynomial;

    std::cout << "Первый полином: " << firstPolynomial << '\n';
    std::cout << "Второй полином: " << secondPolynomial << '\n';
    std::cout << "Сумма двух полиномов: " << firstPolynomial + secondPolynomial << '\n';
    std::cout << "Произведение двух полиномов: " << firstPolynomial * secondPolynomial << '\n';
}

void Handler::DemoModeInit() {
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
