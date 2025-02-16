#include "DataBase.h"
#include <cstddef>
#include <fstream>
#include "Planet.h"

DataBase::DataBase(const char* path) {
    this->stream.open(path, std::ios::app);
}

DataBase::~DataBase() {
    if (this->stream.is_open()) {
        this->stream.close();
    }
}

void DataBase::ReadDataBaseFromFile() {
    while (!stream.eof()) {
        Space::Planet planet;
        
        stream >> planet;

        this->data.Push(planet);
    }
}

void DataBase::WriteDataBaseToFile() {

}

void DataBase::SortDataBase() {

}

void DataBase::AddToDataBase() {

}

void DataBase::DeleteFromDataBase() {

}

void DataBase::PrintDataBase() {
    for (size_t i = 0; i < this->data.GetLength(); i++) {
        this->data[i].Print();
    }
}
