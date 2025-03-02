#include "Planet.h"
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

using std::size_t;

namespace {
const size_t kBufferSize = 256;
}

namespace Space {

size_t Planet::totalCount = 0;

Planet::Planet() {
    this->InitId();

    std::cout << "Создание ID " << this->id << '\n';
};

Planet::Planet(Planet& planet) : diameter(planet.diameter), lifeExists(planet.lifeExists), satellitesCount(planet.satellitesCount) {
    this->InitId();
    size_t nameLength = strlen(planet.name) + 1;
    this->InitName(planet.name, nameLength);

    std::cout << "Создание ID " << this->id << '\n';
}

Planet::Planet(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount)
    : diameter(diameter), lifeExists(lifeExists), satellitesCount(satellitesCount) {
    this->InitId();
    size_t nameLength = strlen(name) + 1;
    this->InitName(name, nameLength);

    std::cout << "Создание ID " << this->id << '\n';
}

Planet::~Planet() {
    delete[] this->name;

    std::cout << "Удаление ID " << this->id << '\n';
}

Planet& Planet::operator=(const Planet& planet) {
    size_t nameLength = strlen(planet.name) + 1;
    this->InitName(planet.name, nameLength);
    this->diameter = planet.diameter;
    this->lifeExists = planet.lifeExists;
    this->satellitesCount = planet.satellitesCount;

    return *this;
}

void Planet::InitId() {
    ++(this->totalCount);
    this->id = this->totalCount;
}

void Planet::InitName(const char* name, size_t nameLength) {
    this->nameLength = nameLength;
    this->name = new char[this->nameLength];

    for (size_t i = 0; i < this->nameLength; i++) {
        this->name[i] = name[i];
    }
}

size_t Planet::GetTotalCount() {
    return this->totalCount;
}

size_t Planet::GetId() {
    return this->id;
}

char* Planet::GetName() {
    return this->name;
}

size_t Planet::GetDiameter() {
    return this->diameter;
}

bool Planet::GetLifeExists() {
    return this->lifeExists;
}

size_t Planet::GetSatellitesCount() {
    return this->satellitesCount;
}

void Planet::SetTotalCount(size_t totalCount) {
    this->totalCount = totalCount;
}

void Planet::SetName(const char* name) {
    size_t newNameLength = strlen(name) + 1;

    if (this->nameLength != newNameLength) {
        delete[] this->name;
    }

    this->InitName(name, newNameLength);
}

void Planet::SetDiameter(size_t diameter) {
    this->diameter = diameter;
}

void Planet::SetLifeExists(bool lifeExists) {
    this->lifeExists = lifeExists;
}

void Planet::SetSatellitesCount(size_t satellitesCount) {
    this->satellitesCount = satellitesCount;
}

void Planet::Print() {
    std::cout << "Название: " << this->name << "; Диаметр: " << this->diameter << "; Жизнь: " << this->lifeExists
              << "; Спутники: " << this->satellitesCount << ";\n";
}
}  // namespace Space

std::ofstream& operator<<(std::ofstream& stream, Space::Planet& planet) {
    stream << planet.GetName() << ' ' << planet.GetDiameter() << ' ' << planet.GetLifeExists() << ' ' << planet.GetSatellitesCount() << '\n';
    return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Space::Planet& planet) {
    char name[kBufferSize]{'\0'};
    size_t diameter = 0;
    bool lifeExists = false;
    size_t satellitesCount = 0;

    stream >> name;
    stream >> diameter >> lifeExists >> satellitesCount;

    stream.ignore(kBufferSize, '\n');

    planet.SetName(name);
    planet.SetDiameter(diameter);
    planet.SetLifeExists(lifeExists);
    planet.SetSatellitesCount(satellitesCount);
    return stream;
}
