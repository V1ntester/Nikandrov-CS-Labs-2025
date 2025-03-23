#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <cstring>
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

    TypeName* data = nullptr;

    void Resize(size_t length);

 protected:
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
    TypeName operator[](unsigned index) const;

    bool operator==(const Vector<TypeName>& vector);

    size_t GetLength() const;

    void Add(TypeName value);
    void Delete(size_t index);

    auto Find(TypeName value) const;
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
bool Vector<char*>::EqualElements(char* firstElement, char* secondElement) const {
    return strcmp(firstElement, secondElement) == 0;
}


template<>
bool Vector<char*>::CompareElements(char* firstElement, char* secondElement, bool reverse) const {
    if (!reverse) {
        return strcmp(firstElement, secondElement) > 0;
    }

    return strcmp(firstElement, secondElement) < 0;
}


template<typename TypeName>
void Vector<TypeName>::Resize(size_t length) {
    TypeName* newData = new TypeName[length];
    size_t valuesToCopyCount = (length > this->filled ? this->filled : length);

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

    for (size_t i = 0; i < vector.filled; i++) {
        this->data[i] = vector.data[i];
    }

    this->filled = vector.filled;
    this->length = vector.length;
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
    this->Resize(1);
}

template<typename TypeName>
Vector<TypeName>::Vector(TypeName value) {
    this->Resize(1);

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

template<typename TypeName>
Vector<TypeName>& Vector<TypeName>::operator=(const Vector<TypeName>& vector) {
    this->Copy(vector);

    return *this;
}

template<typename TypeName>
TypeName& Vector<TypeName>::operator[](unsigned index) {
    if (index >= filled) {
        throw std::out_of_range("Index  out of range");
    }

    return this->data[index];
}

template<typename TypeName>
TypeName Vector<TypeName>::operator[](unsigned index) const {
    if (index >= filled) {
        throw std::out_of_range("Index  out of range");
    }

    return this->data[index];
}

template<typename TypeName>
bool Vector<TypeName>::operator==(const Vector<TypeName>& vector) {
    if (this->GetLength() != vector.GetLength()) {
        return false;
    }

    for (size_t i = 0; i < this->GetLength(); i++) {
        if (!vector.isElement((*this)[i])) {
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
        this->Resize(this->length * 2);
    }

    if (this->length > 0) {
        this->data[filled] = value;

        ++this->filled;
    }
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

template<typename TypeName>
auto Vector<TypeName>::Find(TypeName value) const {
    bool isSucess = false;
    size_t index = 0;

    for (size_t i = 0; i < this->filled; i++) {
        if (this->data[i] == value) {
            isSucess = true;
            index = i;

            break;
        }
    }

    return FindAnswer(isSucess, index);
}

#endif
