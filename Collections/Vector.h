#pragma once

#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>

namespace {
struct FindAnswer {
    bool isSuccess = false;
    size_t index = 0;
};
}  // namespace

template<typename TypeName>
class Vector {
 private:
    size_t filled = 0;
    size_t length = 0;

    void Resize(size_t length);

 protected:
    TypeName* data = nullptr;

    bool EqualElements(TypeName firstElement, TypeName secondElement) const;
    bool CompareElements(TypeName firstElement, TypeName secondElement, bool reverse = false) const;

    void Copy(const Vector& vector);
    void Sort();

 public:
    Vector();
    Vector(TypeName value);
    Vector(const Vector& vector);

    ~Vector();

    Vector& operator=(const Vector& vector);

    TypeName& operator[](unsigned index);

    bool operator==(const Vector<TypeName>& vector) const;

    size_t GetLength() const;

    void Add(TypeName value);
    void Delete(size_t index);

    auto Find(TypeName value) const;

    template<typename FriendTypeName>
    friend std::ostream& operator<<(std::ostream& stream, const Vector<FriendTypeName>& vector);
};

template<typename TypeName>
bool Vector<TypeName>::EqualElements(TypeName firstElement, TypeName secondElement) const {
    return firstElement == secondElement;
}

template<typename TypeName>
bool Vector<TypeName>::CompareElements(TypeName firstElement, TypeName secondElement, bool reverse) const {
    if (!reverse) {
        return firstElement > secondElement;
    }

    return firstElement < secondElement;
}

template<>
bool Vector<char*>::CompareElements(char* firstElement, char* secondElement, bool reverse) const {
    if (!firstElement || !secondElement) {
        return false;
    }

    if (!reverse) {
        return strcmp(firstElement, secondElement) > 0;
    }

    return strcmp(firstElement, secondElement) < 0;
}

template<>
bool Vector<const char*>::CompareElements(const char* firstElement, const char* secondElement, bool reverse) const {
    if (!reverse) {
        return strcmp(firstElement, secondElement) > 0;
    }

    return strcmp(firstElement, secondElement) < 0;
}

template<>
bool Vector<char*>::EqualElements(char* firstElement, char* secondElement) const {
    if (!firstElement || !secondElement) {
        return false;
    }

    return strcmp(firstElement, secondElement) == 0;
}

template<>
bool Vector<const char*>::EqualElements(const char* firstElement, const char* secondElement) const {
    return strcmp(firstElement, secondElement) == 0;
}

template<typename TypeName>
void Vector<TypeName>::Resize(size_t length) {
    TypeName* newData = new TypeName[length];
    size_t valuesToCopyCount = std::min(this->filled, length);

    for (size_t i = 0; i < valuesToCopyCount; i++) {
        newData[i] = data[i];
    }

    if (this->data) {
        delete[] this->data;
    }

    this->data = newData;

    this->filled = valuesToCopyCount;
    this->length = length;
}

template<>
void Vector<char*>::Resize(size_t length) {
    char** newData = new char*[length];
    size_t valuesToCopyCount = std::min(this->filled, length);

    for (size_t i = valuesToCopyCount; i < this->filled; i++) {
        delete[] this->data[i];
    }

    for (size_t i = 0; i < valuesToCopyCount; i++) {
        newData[i] = data[i];
    }

    if (this->data) {
        delete[] this->data;
    }

    this->data = newData;

    this->filled = valuesToCopyCount;
    this->length = length;
}

template<typename TypeName>
void Vector<TypeName>::Copy(const Vector& vector) {
    this->Resize(vector.length);

    if (vector.length > 0) {
        for (size_t i = 0; i < vector.filled; i++) {
            this->data[i] = vector.data[i];
        }
    }

    this->filled = vector.filled;
}

template<>
void Vector<char*>::Copy(const Vector& vector) {
    this->Resize(vector.length);

    if (vector.length > 0) {
        for (size_t i = 0; i < vector.filled; i++) {
            size_t stringLength = strlen(vector.data[i]) + 1;
            char* string = new char[stringLength];

            strncpy(string, vector.data[i], stringLength);

            this->data[i] = string;
        }
    }

    this->filled = vector.filled;
}

template<typename TypeName>
void Vector<TypeName>::Sort() {
    size_t length = this->GetLength();

    for (size_t i = 0; i < length; i++) {
        bool isSwaped = false;

        for (size_t j = 0; j < length - 1; j++) {
            if (this->CompareElements(this->data[j], this->data[j + 1])) {
                std::swap(this->data[j], this->data[j + 1]);

                isSwaped = true;
            }
        }

        if (!isSwaped) {
            break;
        }
    }
}

template<typename TypeName>
Vector<TypeName>::Vector() {
}

template<typename TypeName>
Vector<TypeName>::Vector(TypeName value) {
    this->Add(value);
}

template<typename TypeName>
Vector<TypeName>::Vector(const Vector& vector) {
    this->Copy(vector);
}

template<typename TypeName>
Vector<TypeName>::~Vector() {
    delete[] this->data;
}

template<>
Vector<char*>::~Vector() {
    for (size_t i = 0; i < this->filled; i++) {
        delete[] this->data[i];
    }

    delete[] this->data;
}

template<typename TypeName>
Vector<TypeName>& Vector<TypeName>::operator=(const Vector<TypeName>& vector) {
    this->Copy(vector);

    return *this;
}

template<typename TypeName>
TypeName& Vector<TypeName>::operator[](unsigned index) {
    if (!this->data || index >= filled) {
        throw std::out_of_range("Index out of range");
    }

    return this->data[index];
}

template<typename TypeName>
bool Vector<TypeName>::operator==(const Vector<TypeName>& vector) const {
    if (this->GetLength() != vector.GetLength()) {
        return false;
    }

    for (size_t i = 0; i < this->GetLength(); i++) {
        auto [isSuccess, index] = this->Find(this->data[i]);

        if (!isSuccess) {
            return false;
        }
    }

    return true;
}

template<typename TypeName>
size_t Vector<TypeName>::GetLength() const {
    return this->filled;
}

template<typename TypeName>
void Vector<TypeName>::Add(TypeName value) {
    if (this->filled == this->length) {
        if (length == 0) {
            this->Resize(1);
        } else {
            this->Resize(this->length * 2);
        }
    }

    this->data[filled] = value;

    ++this->filled;
}

template<>
void Vector<char*>::Add(char* value) {
    if (this->filled == this->length) {
        if (length == 0) {
            this->Resize(1);
        } else {
            this->Resize(this->length * 2);
        }
    }

    size_t stringLength = strlen(value) + 1;
    char* string = new char[stringLength];

    strncpy(string, value, stringLength);

    this->data[filled] = string;

    ++this->filled;
}

template<typename TypeName>
void Vector<TypeName>::Delete(size_t index) {
    for (size_t i = index; i < filled - 1; i++) {
        std::swap(this->data[i], this->data[i + 1]);
    }

    --this->filled;

    if (this->filled == this->length / 4 && this->filled != 0) {
        this->Resize(this->length / 2);
    }
}

template<>
void Vector<char*>::Delete(size_t index) {
    delete[] this->data[index];

    for (size_t i = index; i < filled - 1; i++) {
        std::swap(this->data[i], this->data[i + 1]);
    }

    --this->filled;

    if (this->filled == this->length / 4 && this->filled != 0) {
        this->Resize(this->length / 2);
    }
}

template<typename TypeName>
auto Vector<TypeName>::Find(TypeName value) const {
    bool isSucess = false;
    size_t index = 0;

    for (size_t i = 0; i < this->filled; i++) {
        if (EqualElements(this->data[i], value)) {
            isSucess = true;
            index = i;

            break;
        }
    }

    return FindAnswer{isSucess, index};
}

template<typename TypeName>
std::ostream& operator<<(std::ostream& stream, const Vector<TypeName>& vector) {
    size_t length = vector.GetLength();

    stream << '[';

    for (size_t i = 0; i < length; i++) {
        stream << vector.data[i];

        if (i != length - 1) {
            std::cout << ", ";
        }
    }

    stream << ']';

    return stream;
}
