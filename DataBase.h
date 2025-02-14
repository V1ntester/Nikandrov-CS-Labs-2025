#include <cstddef>
#include <fstream>
#include "Planet/Planet.h"

// namespace DataBase {
template<typename typeName>
class DataBase {
 private:
    typeName* Data = nullptr;
    char* path
    std::fstream stream;

 public:
    void ReadDataBaseFromFile();
    void WriteDataBaseToFile(typeName type);
    void SortDataBase();
    void AddToDataBase();
    void DeleteFromDataBase();
    void PrintDataBase();
};
//};  // namespace DataBase
