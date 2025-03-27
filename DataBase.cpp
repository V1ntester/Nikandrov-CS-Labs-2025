#include "DataBase.h"
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include "Planet/Planet.h"

DataBase::DataBase(const char* path, bool isInteractive) : isInteractive(isInteractive) {
    size_t pathLength = strlen(path) + 1;
    this->path = new char[pathLength];

    for (size_t i = 0; i < pathLength; i++) {
        this->path[i] = path[i];
    }
}

DataBase::DataBase(const DataBase& dataBase) : data(dataBase.data) {
    size_t pathLength = strlen(dataBase.path) + 1;
    this->path = new char[pathLength];

    strncpy(this->path, dataBase.path, pathLength);
}

DataBase::~DataBase() {
    for (size_t i = 0; i < this->data.GetLength(); i++) {
        delete this->data[i];
    }
}

DataBase& DataBase::operator=(const DataBase& dataBase) {
    this->data = dataBase.data;

    size_t pathLength = strlen(dataBase.path) + 1;
    char* newPath = new char[pathLength];

    strncpy(newPath, path, pathLength);

    delete[] this->path;

    this->path = newPath;

    return *this;
}

size_t DataBase::GetLength() {
    return this->data.GetLength();
}

void DataBase::ReadFromFile() {
    std::ifstream stream;
    stream.open(this->path, std::ios::in | std::ios::app);

    size_t linesCount = 0;

    stream >> linesCount;

    for (size_t i = 0; i < this->data.GetLength(); i++) {
        delete this->data[i];
    }

    this->data.Clear();

    for (size_t i = 0; i < linesCount; i++) {
        Planet* planet = new Planet();

        stream >> *planet;

        this->data.Push(planet);
    }

    stream.close();
}

void DataBase::WriteToFile() {
    std::ofstream stream;
    stream.open(this->path, std::ios::out | std::ios::trunc);

    stream << this->data.GetLength() << '\n';

    for (size_t i = 0; i < this->data.GetLength(); i++) {
        stream << *this->data[i];
    }

    stream.close();
}

void DataBase::Sort() {
    for (size_t i = 0; i < this->GetLength(); i++) {
        bool isSwaped = false;

        for (size_t j = 0; j < this->GetLength() - 1; j++) {
            if (*(this->data[j]) < *(this->data[j + 1])) {
                isSwaped = true;
                std::swap(this->data[j], this->data[j + 1]);
            }
        }

        if (!isSwaped) {
            break;
        }
    }
}

void DataBase::Add() {
    Planet* planet = new Planet();

    if (this->isInteractive) {
        std::cin >> *planet;
    }

    this->data.Push(planet);
}

void DataBase::Delete() {
    size_t index = 0;

    if (this->isInteractive) {
        std::cout << "Введите индекс элемента: ";
        std::cin >> index;
    }

    if (index >= this->data.GetLength()) {
        return;
    }

    this->data.Delete(index);
}

std::ostream& operator<<(std::ostream& stream, DataBase& dataBase) {
    for (size_t i = 0; i < dataBase.data.GetLength(); i++) {
        std::cout << "Индекс: " << i << "; " << *dataBase.data[i];
    }

    return stream;
}
