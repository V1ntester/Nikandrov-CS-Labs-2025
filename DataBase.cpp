#include "DataBase.h"
#include <cstddef>
#include <cstring>
#include <fstream>
#include "Planet/Planet.h"

DataBase::DataBase(const char* path) {
    this->stream.open(path, std::ios::app);

    size_t pathLength = strlen(path) + 1;
    this->path = new char[pathLength];

    for (size_t i = 0; i < pathLength; i++) {
        this->path[i] = path[i];
    }
}

DataBase::~DataBase() {
    if (this->stream.is_open()) {
        this->stream.close();
    }

    for (size_t i = 0; i < this->data.GetLength(); i++) {
        delete data[i];
    }
}

void DataBase::ReadDataBaseFromFile() {
    while (!this->stream.eof()) {
        Space::Planet* planet = new Space::Planet;
        
        this->stream >> *planet;

        this->data.Push(planet);
    }
}

void DataBase::WriteDataBaseToFile() {
    if (this->stream.is_open()) {
        this->stream.close();
    }

    this->stream.open(this->path, std::ios::in | std::ios::out | std::ios::trunc);

    for (size_t i = 0; i < this->data.GetLength(); i++) {
        this->stream << this->data[i];
    }
}

void DataBase::SortDataBase() {

}

void DataBase::AddToDataBase(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount) {
    Space::Planet* planet = new Space::Planet(name, diameter, lifeExists, satellitesCount);

    this->data.Push(planet);
}

void DataBase::DeleteFromDataBase(size_t index) {

}

void DataBase::PrintDataBase() {
    for (size_t i = 0; i < this->data.GetLength(); i++) {
        this->data[i]->Print();
    }
}
