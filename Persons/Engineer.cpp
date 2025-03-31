#include "Engineer.h"

#include <iostream>

Engineer::Engineer() {
    std::cout << "Engineer()\n";
}

Engineer::Engineer(const char* name, size_t salary, double efficiency, double teamWork, double analyticalThinking, double communicationSkills)
    : Person(name, salary, efficiency, teamWork), analyticalThinking(analyticalThinking), communicationSkills(communicationSkills) {
    std::cout << "Engineer()\n";
}

Engineer::Engineer(const Engineer& engineer) : Person(engineer.name, engineer.salary, engineer.efficiency, engineer.teamWork), analyticalThinking(engineer.analyticalThinking), communicationSkills(engineer.communicationSkills) {
    std::cout << "Engineer()\n";
}

Engineer::~Engineer() {
    std::cout << "~Engineer()\n";
}

void Engineer::Show() const {
    std::cout << "Имя: " << this->name << "; ";
    std::cout << "Зарплата: " << this->salary << "; ";
    std::cout << "Работоспособность: " << this->efficiency << "; ";
    std::cout << "Работа в команде: " << this->teamWork << "; ";
    std::cout << "Аналитическое мышление: " << this->analyticalThinking << "; ";
    std::cout << "Коммуникабельность: " << this->communicationSkills << ";\n";
}

Engineer& Engineer::operator=(const Engineer& engineer) = default;
