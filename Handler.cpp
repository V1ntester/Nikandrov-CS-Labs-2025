#include "Handler.h"

#include <iostream>

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
