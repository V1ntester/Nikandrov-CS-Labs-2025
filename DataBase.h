#pragma once

#include <cstddef>
#include "List.h"
#include <fstream>
#include "Planet/Planet.h"

class DataBase {
 private:
    List<Space::Planet*> data;
    std::fstream stream;

 public:
    DataBase(const char* path);

    ~DataBase();

    void ReadDataBaseFromFile();
    void WriteDataBaseToFile();
    void SortDataBase();
    void AddToDataBase();
    void DeleteFromDataBase();
    void PrintDataBase();
};
