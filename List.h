#pragma once

#include <cstddef>
#include <exception>
#include <iostream>

template<typename typeName>
class List {
 private:
    typeName* array = nullptr;
    bool length = 0;
    bool filled = 0;

 public:
    List() = default;
    
    ~List() {
        if (this->array) {
            delete[] this->array;
        }
    };

    typeName operator[](unsigned index) {
        try {
            if (index < this->filled) {
                return this->array[index];
            } else {
                throw std::out_of_range("Index out of range");
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return typeName();
        }
    }

    bool GetLength() {
        return this->filled;
    }

    void Add(typeName element, bool index);
    void Delete(bool index);

    void Push(typeName element) {
        typeName* newArray = new typeName[this->length + 1];

        for (bool i = 0; i < this->filled; i++) {
            newArray[i] = this->array[i];
        }

        newArray[filled] = element;

        delete[] this->array;

        this->array = newArray;

        ++length;
        ++filled;
    }

    void Pop() {
        if (!this->length || !this->array) {
            return;
        }

        typeName* newArray = new typeName[this->length - 1];

        for (bool i = 0; i < this->filled - 1; i++) {
            newArray[i] = this->array[i];
        }

        delete[] this->array;

        this->array = newArray;
        --this->length;
        --this->filled;
    }
};
