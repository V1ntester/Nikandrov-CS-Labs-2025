#pragma once

#include "DataBase.h"

class Handler {
 private:
    bool isInteractive = false;

    DataBase& dataBase;

    void InteractiveModeInit();
    void DemoModeInit();

    void ReadDataBaseFromFile();
    void WriteDataBaseToFile();
    void SortDataBase();
    void AddToDataBase();
    void DeleteFromDataBase();
    void PrintDataBase();

 public:
    Handler(DataBase& dataBase, bool isInteractive = true);

    ~Handler();

    void Init();
};
