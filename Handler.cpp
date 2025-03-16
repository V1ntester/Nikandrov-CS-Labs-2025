#include "Handler.h"

#include <iostream>
#include "Fraction/Fraction.h"

void Handler::InteractiveModeInit() {
    Fraction fraction;

    std::cin >> fraction;
    std::cout << "{Ваша дробь} + 1: " << fraction + 1 << '\n';
    std::cout << "{Ваша дробь} + 1.0: " << fraction + 1.0 << '\n';
}

// Test were taken from the lab manual
void Handler::DemoModeInit() {
    Fraction fractionZ(1, 1);

    std::cout << "z=" << fractionZ << std::endl;

    Fraction fractionOne(1, 1);
    Fraction fractionTwo;

    std::cout << "fr2=" << fractionTwo << std::endl;
    std::cout << "fr1=" << fractionOne << std::endl;

    Fraction fractionTestOne = "-1 4/8";

    std::cout << "fr=" << fractionTestOne << std::endl;

    Fraction fractionX(fractionZ);
    Fraction fractionY;

    std::cout << "x=" << fractionX << std::endl;

    double doubleValue = -1.0;

    Fraction fractionTestTwo = doubleValue;

    std::cout << "f=" << fractionTestTwo << std::endl;

    fractionY = fractionX + fractionZ;

    std::cout << "y=" << fractionY << std::endl;

    fractionY += fractionX;
    fractionTestTwo += doubleValue / 1;

    std::cout << "f=" << fractionTestTwo << std::endl;

    fractionY = fractionX + doubleValue;

    std::cout << "y=" << fractionY << std::endl;

    fractionY = doubleValue + fractionY;

    std::cout << "y=" << fractionY << std::endl;

    fractionY += doubleValue;

    std::cout << "y=" << fractionY << std::endl;

    int integerValue = 1;

    fractionY += integerValue;

    std::cout << "y=" << fractionY << std::endl;

    fractionY = integerValue + fractionX;

    std::cout << "y=" << fractionY << std::endl;

    fractionY = fractionX + integerValue;

    std::cout << "y=" << fractionY << std::endl;

    fractionY += doubleValue + integerValue + fractionX;

    std::cout << "y=" << fractionY << std::endl;
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
