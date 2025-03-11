#include "Airport.h"

#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

using std::size_t;

namespace {
const size_t kCodeLength = 4;
const size_t kBufferSize = 256;
}

size_t Airport::totalCount = 0;

void Airport::IdInit() {
    ++this->totalCount;
    this->id = this->totalCount;
}

void Airport::NameInit(const char* name, size_t nameLength) {
    this->nameLength = nameLength;
    this->name = new char[this->nameLength];

    for (size_t i = 0; i < this->nameLength; i++) {
        this->name[i] = name[i];
    }
}

void Airport::NameSet(const char* name) {
    size_t newNameLength = strlen(name) + 1;

    if (this->nameLength != newNameLength) {
        delete[] this->name;
    }

    this->NameInit(name, newNameLength);
}

void Airport::CodeSet(const char* code) {
    for (size_t i = 0; i < kCodeLength; i++) {
        this->code[i] = code[i];
    }
}

Airport::Airport() {
    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
};

Airport::Airport(Airport& airport) : runwaysCount(airport.runwaysCount) {
    size_t nameLength = strlen(airport.name) + 1;
    this->NameInit(airport.name, nameLength);
    this->CodeSet(airport.code);

    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
}

Airport::Airport(const char* name, const char* code, size_t runwaysCount)
    : runwaysCount(runwaysCount) {
    size_t nameLength = strlen(name) + 1;
    this->NameInit(name, nameLength);
    this->CodeSet(code);

    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
}

Airport::~Airport() {
    delete[] this->name;

    std::cout << "Удаление ID " << this->id << '\n';
}

Airport& Airport::operator=(const Airport& airport) {
    size_t nameLength = strlen(airport.name) + 1;
    this->NameInit(airport.name, nameLength);
    this->CodeSet(airport.code);
    this->runwaysCount = airport.runwaysCount;

    return *this;
}

bool Airport::operator==(const Airport& airport) const {
    return (strcmp(this->name, airport.name) == 0) && (strcmp(this->code, airport.code) == 0) && (this->runwaysCount == airport.runwaysCount);
}

bool Airport::operator<(const Airport& airport) const {
    return this->runwaysCount < airport.runwaysCount;
}

bool Airport::operator>(const Airport& airport) const {
    return airport < *this;
}

void Airport::Print() {
    std::cout << "Название: " << this->name << "; Код: " << this->code << "; Полосы: " << this->runwaysCount << ";\n";
}

std::ofstream& operator<<(std::ofstream& stream, Airport& airport) {
    stream << airport.name << ' ' << airport.code << ' ' << airport.runwaysCount << '\n';
    return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Airport& airport) {
    char name[kBufferSize]{'\0'};
    char code[4] {'\0'};
    size_t runwaysCount = 0;

    stream >> name;
    stream >> code;
    stream >> runwaysCount;

    airport.NameSet(name);
    airport.CodeSet(code);
    airport.runwaysCount = runwaysCount;
    return stream;
}
