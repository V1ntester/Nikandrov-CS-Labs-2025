#include "DataBase.h"
#include <cstring>
#include <fstream>
#include "Planet/Planet.h"

namespace DataBase {
void WriteToDataBase(Space::Planet planet, char* path) {
    std::ofstream stream;
    stream.open(path);

    if (!stream.is_open()) {
        return;
    }

    stream << planet;
}
}  // namespace DataBase
