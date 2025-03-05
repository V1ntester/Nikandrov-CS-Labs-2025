#include <cstring>
#include "DataBase.h"
#include "Handler.h"

#include "Planet/Planet.h"

namespace {
const char path[] = "DataBase.txt";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    DataBase dataBase(path);

    bool isInteractive = false;

    if (argc == 2 && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    Handler handler(dataBase, isInteractive);
    handler.Init();

    return 0;
}
