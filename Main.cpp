#include <iostream>
#include <cstring>
#include "MyMath.h"
#include "MyAnimalArt.h"

namespace {
    const int kFirstValueForSum = 4;
    const int kSecondValueForSum = 5;
}

int main ([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    std::cout << "Я умею считать: 2 + 2 = " << MyMath::Sum(kFirstValueForSum, kSecondValueForSum) << "\n\n";
    std::cout << "Твоё животное: \n\n";
    MyAnimalArt::PrintRandomAnimalArt();
    std::cout << '\n';

    return 0;
}
