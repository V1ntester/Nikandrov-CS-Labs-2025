#include "Worker.h"

#include <iostream>

Worker::Worker() {
    std::cout << "Worker()\n";
}

Worker::Worker(const char* name, size_t salary, double efficiency, double teamWork, double stamina, double discipline)
    : Person(name, salary, efficiency, teamWork), stamina(stamina), discipline(discipline) {
    std::cout << "Worker()\n";
}

Worker::Worker(const Worker& worker)
    : Person(worker.name, worker.salary, worker.efficiency, worker.teamWork), stamina(worker.stamina), discipline(worker.discipline) {
    std::cout << "Worker()\n";
}

Worker::~Worker() {
    std::cout << "~Worker()\n";
}

void Worker::Show() const {
    std::cout << "Имя: " << this->name << "; ";
    std::cout << "Зарплата: " << this->salary << "; ";
    std::cout << "Работоспособность: " << this->efficiency << "; ";
    std::cout << "Работа в команде: " << this->teamWork << "; ";
    std::cout << "Выносливость: " << this->stamina << "; ";
    std::cout << "Дисциплина: " << this->discipline << ";\n";
}

Worker& Worker::operator=(const Worker& worker) = default;
