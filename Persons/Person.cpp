#include "Person.h"

#include <cstddef>
#include <cstring>
#include <iostream>

namespace {
const size_t kNameBufferSize = 256;
}

void Person::SetName(const char* name) {
    size_t nameLength = strlen(name) + 1;

    char* newName = new char[nameLength];

    strncpy(newName, name, nameLength);

    if (this->name) {
        delete[] this->name;
    }

    this->name = newName;
}

Person::Person() {
    std::cout << "Person()\n";
}

Person::Person(const char* name, size_t salary, double efficiency, double teamWork) : salary(salary), efficiency(efficiency), teamWork(teamWork) {
    SetName(name);

    std::cout << "Person()\n";
}

Person::Person(const Person& person) : salary(person.salary), efficiency(person.efficiency), teamWork(person.teamWork) {
    SetName(person.name);

    std::cout << "Person()\n";
}

Person::~Person() {
    if (this->name) {
        delete[] this->name;
    }

    std::cout << "~Person()\n";
}

Person& Person::operator=(const Person& person) {
    this->SetName(person.name);

    this->salary = person.salary;
    this->efficiency = person.efficiency;
    this->teamWork = person.teamWork;

    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Person& person) {
    person.Show(stream);

    return stream;
}

std::istream& operator>>(std::istream& stream, Person& person) {
    char namebuffer[kNameBufferSize]{'\0'};

    std::cout << "Введите имя: ";
    stream >> namebuffer;

    person.SetName(namebuffer);

    std::cout << "Введите зарплату: ";
    stream >> person.salary;

    std::cout << "Введите работоспособность: ";
    stream >> person.efficiency;

    std::cout << "Введите работу в команде: ";
    stream >> person.teamWork;

    return stream;
}
