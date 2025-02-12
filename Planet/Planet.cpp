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

void Planet::Print() {
    std::cout << "Название: " << this->name << " Диаметр: " << this->diameter << " Жизнь" << this->population
              << " Спутники: " << this->satellitesCount << '\n';
}
