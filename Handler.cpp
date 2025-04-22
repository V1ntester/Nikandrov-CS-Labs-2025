#include "Handler.h"

#include "Persons/Employee.h"
#include "Persons/Engineer.h"
#include "Persons/Person.h"
#include "Persons/Worker.h"

#include "Stack/Stack.h"

namespace {
const size_t kStreamIgnoreSymbols = 256;

void NavigationItemsPrint() {
    std::cout << "Выберите одно из действий: \n";
    std::cout << "a — Вывести\n";
    std::cout << "b — Добавить\n";
    std::cout << "с — Удалить (Pop)\n";
    std::cout << "d — Очистить\n";
    std::cout << "q — Выход\n\n";

    std::cout << "Действие: ";
}

void PrintStack(Stack<Person*>& stack) {
    Stack<Person*> tempStack = stack;

    while (!tempStack.Empty()) {
        std::cout << *tempStack.Top() << '\n';

        tempStack.Pop();
    }
}

void AddToStack(Stack<Person*>& stack) {
    size_t objectIndex = 0;

    std::cout << "Введите номер объекта (Worker — 1; Employee — 2; Engineer — 3): ";
    std::cin >> objectIndex;

    switch (objectIndex) {
        case 1: {
            Worker* worker = new Worker;

            std::cin >> *worker;

            stack.Push(worker);

            break;
        }
        case 2: {
            Employee* employee = new Employee;

            std::cin >> *employee;

            stack.Push(employee);

            break;
        }
        case 3: {
            Engineer* engineer = new Engineer;

            std::cin >> *engineer;

            stack.Push(engineer);

            break;
        }
        default: {
            std::cout << "Неверный номер\n";
            break;
        }
    }
}

void PopFromStack(Stack<Person*>& stack) {
    if (stack.Empty()) {
        return;
    }

    delete stack.Top();

    stack.Pop();
}

void ClearStack(Stack<Person*>& stack) {
    while (!stack.Empty()) {
        delete stack.Top();

        stack.Pop();
    }
}

}  // namespace

void Handler::InteractiveModeInit() {
    Stack<Person*> stack;

    char userAnswer = ' ';

    while (userAnswer != 'q') {
        NavigationItemsPrint();

        std::cin >> userAnswer;

        std::cin.ignore(kStreamIgnoreSymbols, '\n');

        switch (userAnswer) {
            case 'a':
                PrintStack(stack);
                break;
            case 'b':
                AddToStack(stack);
                break;
            case 'c':
                PopFromStack(stack);
                break;
            case 'd':
                ClearStack(stack);
                break;
            case 'q':
                std::cout << "\nMeow!\n";
                break;
            default:
                std::cout << "Действие не найдено\n\n";
                break;
        }

        std::cout << '\n';
    }
}

void Handler::DemoModeInit() {
    Stack<Person*> stack;

    stack.Push(new Worker("Volodya", 0, 0, 0, 1, 0));
    stack.Push(new Engineer("Vitalya", 0, 1, 0, 0, 0));
    stack.Push(new Employee("Veniamin", 1, 0, 0, 0, 0));

    std::cout << '\n';

    PrintStack(stack);

    std::cout << '\n';

    ClearStack(stack);
}

Handler::Handler(bool isInteractive) : isInteractive(isInteractive) {
}

Handler::~Handler() = default;

void Handler::Init() {
    this->isInteractive ? this->InteractiveModeInit() : this->DemoModeInit();
}
