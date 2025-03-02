#include <cstring>
#include <iostream>
#include "DataBase.h"
#include "Planet/Planet.h"
#include "List.h"

namespace {
    const char path[] = "Planet.txt";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    DataBase dataBase(path);

    dataBase.ReadDataBaseFromFile();
    //dataBase.AddToDataBase("Earth", 1, true, 1);
    //dataBase.AddToDataBase("Mercury", 1, false, 1);
    dataBase.WriteDataBaseToFile();

    dataBase.PrintDataBase();

    return 0;
}
