#pragma once

#include <cstddef>
#include <fstream>
#include "List.h"
#include "Planet/Planet.h"

class DataBase {
 private:
    List<Space::Planet*> data;
    char* path = nullptr;

 public:
    DataBase(const char* path);

    ~DataBase();

    size_t GetLength();

    void ReadFromFile();
    void WriteToFile();
    void Sort();
    void Add(Space::Planet* planet);
    void Delete(size_t index);
    void Print();
};
