#include "Worker.h"

#include <iostream>

namespace {
const size_t kNameBufferSize = 256;
}

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

void Worker::Show(std::ostream& stream) const {
    stream << "Имя: " << this->name << "; ";
    stream << "Зарплата: " << this->salary << "; ";
    stream << "Работоспособность: " << this->efficiency << "; ";
    stream << "Работа в команде: " << this->teamWork << "; ";
    stream << "Выносливость: " << this->stamina << "; ";
    stream << "Дисциплина: " << this->discipline << ";";
}

Worker& Worker::operator=(const Worker& worker) = default;

std::istream& operator>>(std::istream& stream, Worker& worker) {
    char namebuffer[kNameBufferSize]{'\0'};

    std::cout << "Введите имя: ";
    stream >> namebuffer;

    worker.SetName(namebuffer);

    std::cout << "Введите зарплату: ";
    stream >> worker.salary;

    std::cout << "Введите работоспособность: ";
    stream >> worker.efficiency;

    std::cout << "Введите работу в команде: ";
    stream >> worker.teamWork;

    std::cout << "Введите выносливость: ";
    stream >> worker.efficiency;

    std::cout << "Введите дисциплину: ";
    stream >> worker.teamWork;

    return stream;
}
