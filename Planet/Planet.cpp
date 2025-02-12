#include "Planet.h"
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

using std::size_t;

namespace {
const size_t kBufferSize = 256;
}

std::ifstream& operator>>(std::ifstream& in, Planet planet) {
    char name[kBufferSize]{'\0'};
    size_t diameter = 0;
    size_t population = 0;
    size_t satellitesCount = 0;

    in.getline(name, kBufferSize - 1, ' ');
    in >> diameter >> population >> satellitesCount;

    planet.SetName(name);
    planet.SetDiameter(diameter);
    planet.SetPopulation(population);
    planet.SetSatellitesCount(satellitesCount);
    return in;
}

std::ofstream& operator<<(std::ofstream& out, Planet planet) {
    out << planet.GetName() << ' ' << planet.GetDiameter() << ' ' << planet.GetPopulation() << ' ' << planet.GetSatellitesCount() << '\n';
    return out;
}

void Planet::InitName(const char* name, size_t nameLength) {
    this->nameLength = nameLength;
    this->name = new char[this->nameLength];
    strlcpy(this->name, name, this->nameLength);
}

Planet::Planet(const char* name, size_t diameter, size_t population, size_t satellitesCount)
    : id(0), diameter(diameter), population(population), satellitesCount(satellitesCount) {
    size_t nameLength = strlen(name) + 1;
    this->InitName(name, nameLength);
}

Planet::Planet(size_t id, const char* name, size_t diameter, size_t population, size_t satellitesCount)
    : id(id), diameter(diameter), population(population), satellitesCount(satellitesCount) {
    size_t nameLength = strlen(name) + 1;
    this->InitName(name, nameLength);
}

Planet::~Planet() {
    delete[] this->name;
}

char* Planet::GetName() {
    return this->name;
}

size_t Planet::GetDiameter() {
    return this->diameter;
}

size_t Planet::GetPopulation() {
    return this->population;
}

size_t Planet::GetSatellitesCount() {
    return this->satellitesCount;
}

void Planet::SetName(const char* name) {
    size_t newNameLength = strlen(name) + 1;

    if (!this->nameLength && this->nameLength != newNameLength) {
        delete[] this->name;
    }

    this->InitName(name, newNameLength);
}

void Planet::SetDiameter(size_t diameter) {
    this->diameter = diameter;
}

void Planet::SetPopulation(size_t population) {
    this->population = population;
}

void Planet::SetSatellitesCount(size_t satellitesCount) {
    this->satellitesCount = satellitesCount;
}

void Planet::Print() {
    std::cout << "Название: " << this->name << "; Диаметр: " << this->diameter << "; Жизнь: " << this->population
              << "; Спутники: " << this->satellitesCount << ";\n";
}
