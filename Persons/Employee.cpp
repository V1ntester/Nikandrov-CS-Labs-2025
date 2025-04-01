#include "Employee.h"

#include <iostream>

namespace {
const size_t kNameBufferSize = 256;
}

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

void Employee::Show(std::ostream& stream) const {
    stream << "Имя: " << this->name << "; ";
    stream << "Зарплата: " << this->salary << "; ";
    stream << "Работоспособность: " << this->efficiency << "; ";
    stream << "Работа в команде: " << this->teamWork << "; ";
    stream << "Стрессоустойчивость: " << this->stressResistance << "; ";
    stream << "Инициативность: " << this->initiative << ";";
}

Employee& Employee::operator=(const Employee& employee) = default;

std::istream& operator>>(std::istream& stream, Employee& employee) {
    char namebuffer[kNameBufferSize]{'\0'};

    std::cout << "Введите имя: ";
    stream >> namebuffer;

    employee.SetName(namebuffer);

    std::cout << "Введите зарплату: ";
    stream >> employee.salary;

    std::cout << "Введите работоспособность: ";
    stream >> employee.efficiency;

    std::cout << "Введите работу в команде: ";
    stream >> employee.teamWork;

    std::cout << "Введите выносливость: ";
    stream >> employee.stressResistance;

    std::cout << "Введите дисциплину: ";
    stream >> employee.initiative;

    return stream;
}
