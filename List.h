#pragma once

#include <cstddef>
#include <exception>
#include <iostream>

template<typename typeName>
class List {
 private:
    typeName* array = nullptr;

    size_t length = 0;
    size_t filled = 0;

 public:
    List() = default;

    List(const List<typeName>& list) {
        this->array = new typeName[list.length];

        for (size_t i = 0; i < list.filled; i++) {
            this->array[i] = list.array[i];
        }
    }

    ~List() {
        if (this->array) {
            delete[] this->array;
        }
    };

    List& operator=(const List<typeName>& list) {
        typeName* newArray = new typeName[list.length];

        for (size_t i = 0; i < list.filled; i++) {
            newArray[i] = list.array[i];
        }

        delete[] this->array;

        this->array = newArray;

        this->length = list.length;
        this->filled = list.filled;

        return *this;
    }

    typeName& operator[](unsigned index) const {
        if (index < this->filled) {
            return this->array[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    size_t GetLength() const { return this->length; }

    void Push(typeName element) {
        typeName* newArray = new typeName[this->length + 1];

        for (size_t i = 0; i < this->filled; i++) {
            newArray[i] = this->array[i];
        }

        newArray[filled] = element;

        delete[] this->array;

        this->array = newArray;

        ++this->length;
        ++this->filled;
    }

    void Pop() {
        if (!this->length || !this->array) {
            return;
        }

        typeName* newArray = new typeName[this->length - 1];

        for (size_t i = 0; i < this->filled - 1; i++) {
            newArray[i] = this->array[i];
        }

        delete[] this->array;

        this->array = newArray;

        --this->length;
        --this->filled;
    }

    void Delete(size_t index) {
        typeName* newArray = new typeName[this->length - 1];

        for (size_t i = 0; i < index; i++) {
            newArray[i] = this->array[i];
        }

        for (size_t i = index + 1; i < this->filled; i++) {
            newArray[i - 1] = this->array[i];
        }

        delete[] this->array;

        this->array = newArray;

        --this->length;
        --this->filled;
    }

    void Clear() {
        typeName* newArray = nullptr;

        delete[] this->array;

        this->array = newArray;

        this->length = 0;
        this->filled = 0;
    }
};
