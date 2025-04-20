#include "Handler.h"

#include <iostream>
#include "Tasks/Tasks.h"

namespace {
const size_t kTasksCount = 9;

const size_t kStreamIgnoreSymbols = 256;
}  // namespace

void Handler::InteractiveModeInit() {
    Task* tasks[kTasksCount]{new FirstTask(), new SecondTask(),  new ThirdTask(),  new FourthTask(), new FifthTask(),
                             new SixthTask(), new SeventhTask(), new EighthTask(), new NinethTask()};

    for (Task* task : tasks) {
        task->Init();

        delete task;

        std::cout << "\nВведите, чтобы продолжить...  ";

        std::cin.get();
        std::cin.ignore(kStreamIgnoreSymbols, '\n');

        std::cout << '\n';
    }
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

    // FifthTask task;
    // task.Init();

    // SixthTask task;
    // task.Init();

    // SeventhTask task;
    // task.Init();

    // EighthTask task;
    // task.Init();

    NinethTask task;
    task.Init();
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
