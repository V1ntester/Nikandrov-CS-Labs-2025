#pragma once

#include <cstddef>

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

    virtual void Show() const = 0;

    Person& operator=(const Person& person);
};
