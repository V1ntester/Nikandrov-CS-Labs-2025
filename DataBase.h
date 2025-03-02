#pragma once

#include <cstddef>
#include "List.h"
#include <fstream>
#include "Planet/Planet.h"

class DataBase {
 private:
    List<Space::Planet*> data;
    char* path = nullptr;
    std::fstream stream;

 public:
    DataBase(const char* path);

    ~DataBase();

    void ReadDataBaseFromFile();
    void WriteDataBaseToFile();
    void SortDataBase();
    void AddToDataBase(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount);
    void DeleteFromDataBase(size_t index);
    void PrintDataBase();
};
