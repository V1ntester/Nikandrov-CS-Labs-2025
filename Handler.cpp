#include "Handler.h"

#include <cstring>
#include <iostream>
#include "Collections/Set.h"
#include "Collections/Vector.h"

namespace {
const size_t kStringLength = 6;
}

void Handler::InteractiveModeInit() {
    Set<char*> set;

    char* firstString = new char[kStringLength];
    char* secondString = new char[kStringLength];

    strncpy(firstString, "aaacc", kStringLength);
    strncpy(secondString, "aaaaa", kStringLength);

    set.Add(firstString);
    set.Add(secondString);

    Set<char*> setClone(set);

    std::cout << set << '\n';
    std::cout << setClone << '\n';
    std::cout << setClone.isElement(firstString) << '\n';

    delete[] firstString;
    delete[] secondString;
}

void Handler::DemoModeInit() {
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
