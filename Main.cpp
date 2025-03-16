#include <cstring>
#include "Handler.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    bool isInteractive = false;

    if (argc == 2 && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    Handler handler(isInteractive);
    handler.Init();

    return 0;
}
