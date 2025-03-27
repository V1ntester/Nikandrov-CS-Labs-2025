#pragma once

#include <cstddef>
#include <fstream>
#include <iostream>
#include "List.h"
#include "Planet/Planet.h"

class DataBase {
 private:
    bool isInteractive = false;

    List<Planet*> data;
    char* path = nullptr;

 public:
    DataBase(const char* path, bool isInteractive);
    DataBase(const DataBase& dataBase);

    ~DataBase();

    DataBase& operator=(const DataBase& dataBase);

    size_t GetLength();

    void ReadFromFile();
    void WriteToFile();
    void Sort();
    void Add();
    void Delete();

    friend std::ostream& operator<<(std::ostream& stream, DataBase& dataBase);
};
