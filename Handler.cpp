#include "Handler.h"

#include <cmath>
#include <iostream>
#include "Collections/Vector.h"
#include "Collections/Set.h"

void Handler::InteractiveModeInit() {
}

void Handler::DemoModeInit() {
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
