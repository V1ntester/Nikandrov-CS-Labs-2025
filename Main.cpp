#include <cstring>
#include <iostream>
#include "Planet/Planet.h"
#include "List.h"

// namespace {
//     const char* path = "Planets.txt";
// }

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    Space::Planet earth("Earth", 1, true, 1);

    earth.Print();

    Space::Planet mercury("Mercury", 1, false, 0);

    List<int> list;

    list.Push(2);

    std::cout << list[0] << '\n';

    return 0;
}
