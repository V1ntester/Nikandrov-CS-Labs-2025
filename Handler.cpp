#include "Handler.h"

#include <iostream>
#include "Tasks/Tasks.h"

void Handler::InteractiveModeInit() {

}

void Handler::DemoModeInit() {
    // FirstTask task;
    // task.Init();

    // SecondTask task;
    // task.Init();

    // ThirdTask task;
    // task.Init();

    // FourthTask task;
    // task.Init();
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
