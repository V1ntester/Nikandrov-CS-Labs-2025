#pragma once

#include <cstddef>
#include <iostream>

class Person {
 protected:
    char* name = nullptr;

    size_t salary = 0;

    double efficiency = 0.0;
    double teamWork = 0.0;

    void SetName(const char* name);

 public:
    Person();
    Person(const char* name, size_t salary, double efficiency, double teamWork);
    Person(const Person& person);

    virtual ~Person();

    virtual void Show(std::ostream& stream) const = 0;

    Person& operator=(const Person& person);

    friend std::ostream& operator<<(std::ostream& stream, const Person& person);
    friend std::istream& operator>>(std::istream& stream, Person& person);
};
