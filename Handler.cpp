#include "Handler.h"

#include <iostream>
#include "Fraction/Fraction.h"

namespace {
const int kFirstDemoModeTestValue = 10;
const int kSecondDemoModeTestValue = 14;
const double kThirdDemoModeTestValue = -1.25;
const int kFourthDemoModeTestValue = 5;
}  // namespace

void Handler::InteractiveModeInit() {
    Fraction fraction;

    std::cin >> fraction;
    std::cout << "{Ваша дробь} + 1: " << fraction + 1 << '\n';
    std::cout << "{Ваша дробь} + 1.0: " << fraction + 1.0 << '\n';
}

// Test with bad variable names were taken from the lab manual.
void Handler::DemoModeInit() {
    std::cout << "Введите дробь: \n";

    Fraction z;

    std::cin >> z;
    std::cout << "z=" << z << std::endl;

    Fraction fr1(kFirstDemoModeTestValue, kSecondDemoModeTestValue);
    Fraction fr2;

    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;

    Fraction fr = "-1 4/8";

    std::cout << "fr=" << fr << std::endl;

    Fraction x(z);
    Fraction y;

    std::cout << "x=" << x << std::endl;

    double dbl = kThirdDemoModeTestValue;

    Fraction f = dbl;

    std::cout << "f=" << f << std::endl;

    y = x + z;

    std::cout << "y=" << y << std::endl;

    y += x;
    f += dbl / 2;

    std::cout << "f=" << f << std::endl;

    y = x + dbl;

    std::cout << "y=" << y << std::endl;

    y = dbl + y;

    std::cout << "y=" << y << std::endl;

    y += dbl;

    std::cout << "y=" << y << std::endl;

    int i = kFourthDemoModeTestValue;

    y += i;

    std::cout << "y=" << y << std::endl;

    y = i + x;

    std::cout << "y=" << y << std::endl;

    y = x + i;

    std::cout << "y=" << y << std::endl;

    y += dbl + i + x;

    std::cout << "y=" << y << std::endl;
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
