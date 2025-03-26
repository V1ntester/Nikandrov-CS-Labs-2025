#pragma once

#include <cstddef>
#include <fstream>
#include "List.h"
#include "Planet/Planet.h"

class DataBase {
 private:
    List<Planet*> data;
    char* path = nullptr;

 public:
    DataBase(const char* path);
    DataBase(const DataBase& dataBase);

    ~DataBase();

    DataBase& operator=(const DataBase& dataBase);

    size_t GetLength();

    void ReadFromFile();
    void WriteToFile();
    void Sort();
    void Add(const char* planetName, int diameter, bool lifeExists, size_t satellitesCount);
    void Delete(size_t index);
    void Print();
};
