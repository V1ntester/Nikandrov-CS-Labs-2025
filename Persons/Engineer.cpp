#include "Engineer.h"

#include <iostream>

namespace {
const size_t kNameBufferSize = 256;
}

Engineer::Engineer() {
    std::cout << "Engineer()\n";
}

Engineer::Engineer(const char* name, size_t salary, double efficiency, double teamWork, double analyticalThinking, double communicationSkills)
    : Person(name, salary, efficiency, teamWork), analyticalThinking(analyticalThinking), communicationSkills(communicationSkills) {
    std::cout << "Engineer()\n";
}

Engineer::Engineer(const Engineer& engineer)
    : Person(engineer.name, engineer.salary, engineer.efficiency, engineer.teamWork),
      analyticalThinking(engineer.analyticalThinking),
      communicationSkills(engineer.communicationSkills) {
    std::cout << "Engineer()\n";
}

Engineer::~Engineer() {
    std::cout << "~Engineer()\n";
}

void Engineer::Show(std::ostream& stream) const {
    stream << "Имя: " << this->name << "; ";
    stream << "Зарплата: " << this->salary << "; ";
    stream << "Работоспособность: " << this->efficiency << "; ";
    stream << "Работа в команде: " << this->teamWork << "; ";
    stream << "Аналитическое мышление: " << this->analyticalThinking << "; ";
    stream << "Коммуникабельность: " << this->communicationSkills << ";";
}

Engineer& Engineer::operator=(const Engineer& engineer) = default;

std::istream& operator>>(std::istream& stream, Engineer& engineer) {
    char namebuffer[kNameBufferSize]{'\0'};

    std::cout << "Введите имя: ";
    stream >> namebuffer;

    engineer.SetName(namebuffer);

    std::cout << "Введите зарплату: ";
    stream >> engineer.salary;

    std::cout << "Введите работоспособность: ";
    stream >> engineer.efficiency;

    std::cout << "Введите работу в команде: ";
    stream >> engineer.teamWork;

    std::cout << "Введите аналитическое мышление: ";
    stream >> engineer.analyticalThinking;

    std::cout << "Введите коммуникабельность: ";
    stream >> engineer.communicationSkills;

    return stream;
}
