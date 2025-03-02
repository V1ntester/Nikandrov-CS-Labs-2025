#include "DataBase.h"
#include <cstddef>
#include <cstring>
#include <fstream>
#include "Planet/Planet.h"

DataBase::DataBase(const char* path) {
    size_t pathLength = strlen(path) + 1;
    this->path = new char[pathLength];

    for (size_t i = 0; i < pathLength; i++) {
        this->path[i] = path[i];
    }
}

DataBase::~DataBase() {
    for (size_t i = 0; i < this->data.GetLength(); i++) {
        delete data[i];
    }
}

void DataBase::ReadDataBaseFromFile() {
    std::ifstream stream;
    stream.open(this->path, std::ios::in | std::ios::app);

    while (!stream.eof()) {
        Space::Planet* planet = new Space::Planet();

        stream >> *planet;

        this->data.Push(planet);
    }

    stream.close();
}

void DataBase::WriteDataBaseToFile() {
    std::ofstream stream;
    stream.open(this->path, std::ios::out | std::ios::trunc);

    for (size_t i = 0; i < this->data.GetLength(); i++) {
        stream << *this->data[i];
    }

    stream.close();
}

void DataBase::SortDataBase() {

}

void DataBase::AddToDataBase(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount) {
    Space::Planet* planet = new Space::Planet(name, diameter, lifeExists, satellitesCount);

    this->data.Push(planet);
}

void DataBase::DeleteFromDataBase() {

}

void DataBase::PrintDataBase() {
    for (size_t i = 0; i < this->data.GetLength(); i++) {
        this->data[i]->Print();
    }
}
