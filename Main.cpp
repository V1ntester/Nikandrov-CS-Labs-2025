#include <cstring>
#include <iostream>
#include "Planet/Planet.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    Planet earth("Earth", 1, 1, 1);

    earth.Print();

    return 0;
}
