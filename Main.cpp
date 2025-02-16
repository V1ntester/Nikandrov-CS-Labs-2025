#include <cstring>
#include <iostream>
#include "DataBase.h"
#include "Planet/Planet.h"
#include "List.h"

// namespace {
//     const char* path = "Planets.txt";
// }

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    DataBase dataBase("Planet.txt");

    dataBase.ReadDataBaseFromFile();

    dataBase.PrintDataBase();

    return 0;
}
