#include "Handler.h"

#include <iostream>
#include "Persons/Worker.h"

void Handler::InteractiveModeInit() {
    Worker worker("Volodya", 0, 0, 0, 0, 0);

    worker.Show();
}

void Handler::DemoModeInit() {
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
