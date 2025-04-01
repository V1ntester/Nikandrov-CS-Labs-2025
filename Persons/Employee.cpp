#include "Employee.h"

#include <iostream>

Employee::Employee() {
    std::cout << "Employee()\n";
}

Employee::Employee(const char* name, size_t salary, double efficiency, double teamWork, double stressResistance, double initiative)
    : Person(name, salary, efficiency, teamWork), stressResistance(stressResistance), initiative(initiative) {
    std::cout << "Employee()\n";
}

Employee::Employee(const Employee& employee)
    : Person(employee.name, employee.salary, employee.efficiency, employee.teamWork),
      stressResistance(employee.stressResistance),
      initiative(employee.initiative) {
    std::cout << "Employee()\n";
}

Employee::~Employee() {
    std::cout << "~Employee()\n";
}

void Employee::Show() const {
    std::cout << "Имя: " << this->name << "; ";
    std::cout << "Зарплата: " << this->salary << "; ";
    std::cout << "Работоспособность: " << this->efficiency << "; ";
    std::cout << "Работа в команде: " << this->teamWork << "; ";
    std::cout << "Стрессоустойчивость: " << this->stressResistance << "; ";
    std::cout << "Инициативность: " << this->initiative << ";\n";
}

Employee& Employee::operator=(const Employee& employee) = default;
