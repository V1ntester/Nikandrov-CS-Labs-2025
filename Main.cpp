#include <cstring>
#include <iostream>
#include "Planet/Planet.h"

// namespace {
//     const char* path = "Planets.txt";
// }

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    Space::Planet earth("Earth", 1, 1, 1);

    earth.Print();

    return 0;
}
