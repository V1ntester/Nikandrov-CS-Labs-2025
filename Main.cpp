#include <cstring>
#include <iostream>
#include "DataBase.h"
#include "Planet/Planet.h"
#include "List.h"

namespace {
    const char* path = "Planets.txt";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    DataBase dataBase(path);

    //dataBase.ReadDataBaseFromFile();
    dataBase.AddToDataBase("Test", 10, 0, 1);
    dataBase.WriteDataBaseToFile();

    dataBase.PrintDataBase();

    return 0;
}
