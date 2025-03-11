#include "DataBase.h"
#include <cstddef>
#include <cstring>
#include <fstream>
#include "Planet/Planet.h"

namespace {
void Swap(Planet*& firstPlanet, Planet*& secondPlanet) {
    Planet* temp = firstPlanet;
    firstPlanet = secondPlanet;
    secondPlanet = temp;
}
}  // namespace

DataBase::DataBase(const char* path) {
    size_t pathLength = strlen(path) + 1;
    this->path = new char[pathLength];

    for (size_t i = 0; i < pathLength; i++) {
        this->path[i] = path[i];
    }
}

// DataBase::DataBase(const DataBase& dataBase) {

// }

DataBase::~DataBase() {
    for (size_t i = 0; i < this->data.GetLength(); i++) {
        delete this->data[i];
    }
}

// DataBase& DataBase::operator=(const DataBase& dataBase) {
//     // if (this->path) {
//     //     delete [] this->path;
//     // }

//     // size_t newPathLength = 
// }

size_t DataBase::GetLength() {
    return this->data.GetLength();
}

void DataBase::ReadFromFile() { 
    std::ifstream stream;
    stream.open(this->path, std::ios::in | std::ios::app);

    size_t linesCount = 0;

    stream >> linesCount;

    // for (size_t i = 0; i < this->data.GetLength(); i++) {
    //     delete this->data[i];
    //     this->data.Delete(i);
    // }

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
                Swap(this->data[j], this->data[j + 1]);
            }
        }

        if (!isSwaped) {
            break;
        }
    }
}

void DataBase::Add(Planet* planet) {
    this->data.Push(planet);
}

void DataBase::Delete(size_t index) {
    if (index >= this->data.GetLength()) {
        return;
    }

    delete data[index];

    this->data.Delete(index);
}

void DataBase::Print() {
    for (size_t i = 0; i < this->data.GetLength(); i++) {
        std::cout << "Индекс: " << i << "; ";
        this->data[i]->Print();
    }
}
