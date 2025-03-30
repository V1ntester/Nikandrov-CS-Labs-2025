#include "Handler.h"

#include <iostream>
#include "Polynomial/Polynomial.h"

void Handler::InteractiveModeInit() {
    Term term;

    std::cout << "Введите терм: ";
    std::cin >> term;

    std::cout << "Ваш терм: " << term << '\n';
    std::cout << "Сумма двух термов: " << (term + term) << '\n';
    std::cout << "Терм в квадрате: " << (term * term) << '\n';

    std::cout << '\n';

    std::cin.ignore();

    Polynomial polynomial;

    // Example for test: 3x^2 - x^2 -    3x^2 + x ^2 + 5x^5   - 4x^3 +x^2 - 7
    std::cout << "Введите полином: ";
    std::cin >> polynomial;

    std::cout << "Ваш полином: " << polynomial << '\n';
    std::cout << "Сумма двух полиномов: " << (polynomial + polynomial) << '\n';
    std::cout << "Полином в квадрате: " << (polynomial * polynomial) << '\n';
}

void Handler::DemoModeInit() {
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
