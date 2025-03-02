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

    this->stream.open(this->path, std::ios::trunc);

    for (size_t i = 0; i < this->data.GetLength(); i++) {
        this->stream << this->data[i];
    }
}

void DataBase::SortDataBase() {

}

void DataBase::AddToDataBase() {
    
}

void DataBase::DeleteFromDataBase() {

}

void DataBase::PrintDataBase() {
    for (size_t i = 0; i < this->data.GetLength(); i++) {
        this->data[i]->Print();
    }
}
