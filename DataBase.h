#include <cstddef>
#include <fstream>
#include "Planet/Planet.h"

namespace DataBase {
        void ReadDataBaseFromFile();
        void WriteDataBaseToFile(Space::Planet planet, char* path);
        void SortDataBase();
        void AddToDataBase();
        void DeleteFromDataBase();
        void PrintDataBase();
 };
