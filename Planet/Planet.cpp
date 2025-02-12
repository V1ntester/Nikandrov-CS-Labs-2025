#include "Planet.h"
#include <cstddef>
#include <cstring>
#include <iostream>

using std::size_t;

Planet::Planet(char* name, size_t diameter, size_t population, size_t satellitesCount)
    : diameter(diameter), population(population), satellitesCount(satellitesCount) {
    size_t nameLength = strlen(name) + 1;
    this->name = new char[nameLength];

    strlcpy(this->name, name, nameLength);
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

void Planet::SetName(char* name) {
    this->name = name;
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
    std::cout << "Название: " << this->name << " Диаметр: " << this->diameter << " Жизнь" << this->population
              << " Спутники: " << this->satellitesCount << '\n';
}
