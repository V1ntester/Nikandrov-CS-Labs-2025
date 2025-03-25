#include "Planet.h"
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

using std::size_t;

namespace {
const size_t kBufferSize = 256;
}

size_t Planet::totalCount = 0;

void Planet::IdInit() {
    ++this->totalCount;
    this->id = this->totalCount;
}

void Planet::NameInit(const char* name) {
    size_t newNameLength = strlen(name) + 1;

    if (this->nameLength != newNameLength) {
        char* newName = new char[newNameLength];

        strncpy(newName, name, newNameLength);

        delete[] this->name;

        this->name = newName;

        this->nameLength = newNameLength;
    } else {
        strncpy(this->name, name, newNameLength);
    }
}

Planet::Planet() {
    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
};

Planet::Planet(Planet& planet) : diameter(planet.diameter), lifeExists(planet.lifeExists), satellitesCount(planet.satellitesCount) {
    this->NameInit(planet.name);

    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
}

Planet::Planet(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount)
    : diameter(diameter), lifeExists(lifeExists), satellitesCount(satellitesCount) {
    this->NameInit(name);

    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
}

Planet::~Planet() {
    delete[] this->name;

    std::cout << "Удаление ID " << this->id << '\n';
}

Planet& Planet::operator=(const Planet& planet) {
    this->NameInit(planet.name);
    this->diameter = planet.diameter;
    this->lifeExists = planet.lifeExists;
    this->satellitesCount = planet.satellitesCount;

    return *this;
}

bool Planet::operator==(const Planet& planet) const {
    return (strcmp(this->name, planet.name) == 0) && (this->diameter == planet.diameter) && (this->lifeExists == planet.lifeExists) &&
           (this->satellitesCount == planet.satellitesCount);
}

bool Planet::operator<(const Planet& planet) const {
    return this->diameter < planet.diameter;
}

bool Planet::operator>(const Planet& planet) const {
    return planet < *this;
}

void Planet::Print() {
    std::cout << "Название: " << this->name << "; Диаметр: " << this->diameter << "; Жизнь: " << this->lifeExists
              << "; Спутники: " << this->satellitesCount << ";\n";
}

std::ofstream& operator<<(std::ofstream& stream, Planet& planet) {
    stream << planet.name << ' ' << planet.diameter << ' ' << planet.lifeExists << ' ' << planet.satellitesCount << '\n';
    return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Planet& planet) {
    char name[kBufferSize]{'\0'};
    size_t diameter = 0;
    bool lifeExists = false;
    size_t satellitesCount = 0;

    stream >> name;
    stream >> diameter >> lifeExists >> satellitesCount;

    planet.NameInit(name);
    planet.diameter = diameter;
    planet.lifeExists = lifeExists;
    planet.satellitesCount = satellitesCount;
    return stream;
}
