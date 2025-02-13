#include <cstddef>
#include <fstream>
#include "Planet/Planet.h"

namespace DataBase {
        void ReadDataBaseFromFile();
        void WriteDataBaseToFile();
        void SortDataBase();
        void AddToDataBase(Space::Planet planet, char* path);
        void DeleteFromDataBase();
        void PrintDataBase();
 };
