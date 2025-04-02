#include "Handler.h"

#include <cmath>
#include <iostream>
#include "Stack/Stack.h"

namespace {
const int kEvenPrimeDivisior = 2;

// const int kTestValue = 340;

void Multipliers(int sourceValue, Stack<int>& stack) {
    if (sourceValue < 0) {
        stack.Push(-1);
    }

    int value = std::abs(sourceValue);

    while (!(value % kEvenPrimeDivisior)) {
        stack.Push(kEvenPrimeDivisior);
        value /= kEvenPrimeDivisior;
    }

    for (size_t i = kEvenPrimeDivisior + 1; i < static_cast<size_t>(std::sqrt(std::abs(sourceValue))) + kEvenPrimeDivisior + 1; i++) {
        if (!(value % i)) {
            stack.Push(static_cast<int>(i));
            value /= static_cast<int>(i);
        }
    }

    if (stack.Empty()) {
        stack.Push(value);
    }
}
}  // namespace

void Handler::InteractiveModeInit() {
    int value = 0;

    std::cout << "Введите значение: ";
    std::cin >> value;

    Stack<int> stack;

    Multipliers(value, stack);

    std::cout << "Делители " << value << ": ";

    Stack<int> reverseStack;

    while (!stack.Empty()) {
        std::cout << stack.Top() << ' ';
        reverseStack.Push(stack.Top());
        stack.Pop();
    }

    std::cout << "\n";
    std::cout << "Делители " << value << ": ";

    while (!reverseStack.Empty()) {
        std::cout << reverseStack.Top() << ' ';
        reverseStack.Pop();
    }

    std::cout << "\n";
}

void Handler::DemoModeInit() {
    Stack<const char*> firstStack;

    firstStack.Push("pam");
    firstStack.Push("pum");
    firstStack.Push("pim");

    Stack<const char*> secondStack(firstStack);
    Stack<const char*> thirdStack;
    thirdStack = firstStack;

    std::cout << "First stack: \n" << firstStack << '\n';

    while (!firstStack.Empty() && !secondStack.Empty() && !thirdStack.Empty()) {
        std::cout << firstStack.Top() << ' ' << secondStack.Top() << ' ' << thirdStack.Top() << '\n';
        firstStack.Pop();
        secondStack.Pop();
        thirdStack.Pop();
    }
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
