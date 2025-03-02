#include "DataBase.h"
#include <cstddef>
#include <fstream>
#include "Planet/Planet.h"

DataBase::DataBase(const char* path) {
    this->stream.open(path, std::ios::app);
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
    //while (!stream.eof()) {
        // Space::Planet* planet = new Space::Planet;
        
        //stream >> *planet;

        // this->data.Push(planet);

        // planet->Print();
    //}
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
        this->data[i]->Print();
    }
}
