#include "Handler.h"

#include <cmath>
#include <iostream>
#include "Stack/Stack.h"

// namespace {
// const int kEvenPrimeDivisior = 2;

// void Multipliers(int value, Stack<int> stack) {
//     while (!value % kEvenPrimeDivisior) {
//         stack.Push(static_cast<int>(kEvenPrimeDivisior));
//         value /= static_cast<int>(kEvenPrimeDivisior);
//     }

//     for (size_t i = kEvenPrimeDivisior + 1; i < static_cast<size_t>(sqrt(value)) + 1; i++) {
//         if (!value % i) {
//             stack.Push(static_cast<int>(i));
//             value /= static_cast<int>(i);
//         }
//     }
// }
// }  // namespace

void Handler::InteractiveModeInit() {
    // int value = 0;

    // std::cout << "Введите значение: ";
    // std::cin >> value;

    // Stack<int> stack;

    // Multipliers(value, stack);

    // std::cout << "Делители: ";

    // while (!stack.Empty()) {
    //     std::cout << stack.Top() << ' ';
    //     stack.Pop();
    // }

    // std::cout << '\n';

    Stack<int> stack;
    stack.Push(1);
}

void Handler::DemoModeInit() {
    Stack<int> stack;
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
