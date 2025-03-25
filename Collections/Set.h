#ifndef SET_H
#define SET_H

#include <iostream>
#include "Vector.h"

template<typename TypeName>
class Set : protected Vector<TypeName> {
 public:
    Set() = default;
    Set(TypeName value);
    Set(const Set& set);

    ~Set();

    Set& operator=(const Set& set);

    TypeName& operator[](unsigned index);
    TypeName operator[](unsigned index) const;

    Set& operator+=(const Set& set);
    Set& operator-=(const Set& set);
    Set& operator*=(const Set& set);

    bool operator==(const Set& set) const;

    size_t GetLength() const;

    void Add(TypeName value);
    void Delete(TypeName value);

    bool isElement(TypeName value) const;

    template<typename FriendTypeName>
    friend std::ostream& operator<<(std::ostream& stream, const Set<FriendTypeName>& set);

    template<typename FriendTypeName>
    friend Set<FriendTypeName> operator+(const Set<FriendTypeName>& firstSet, const Set<FriendTypeName>& secondSet);
    template<typename FriendTypeName>
    friend Set<FriendTypeName> operator-(const Set<FriendTypeName>& firstSet, const Set<FriendTypeName>& secondSet);
    template<typename FriendTypeName>
    friend Set<FriendTypeName> operator*(const Set<FriendTypeName>& firstSet, const Set<FriendTypeName>& secondSet);
};

template<typename TypeName>
Set<TypeName>::Set(TypeName value) : Vector<TypeName>(value) {
}

template<typename TypeName>
Set<TypeName>::Set(const Set& set) : Vector<TypeName>(set) {
}

template<typename TypeName>
Set<TypeName>::~Set() {
}

template<typename TypeName>
Set<TypeName>& Set<TypeName>::operator=(const Set<TypeName>& set) {
    this->Copy(set);

    return *this;
}

template<typename TypeName>
TypeName& Set<TypeName>::operator[](unsigned index) {
    return Vector<TypeName>::operator[](index);
}

template<typename TypeName>
TypeName Set<TypeName>::operator[](unsigned index) const {
    return Vector<TypeName>::operator[](index);
}

template<typename TypeName>
Set<TypeName>& Set<TypeName>::operator+=(const Set<TypeName>& set) {
    for (size_t i = 0; i < set.GetLength(); i++) {
        this->Add(set[i]);
    }

    return *this;
}

template<typename TypeName>
Set<TypeName>& Set<TypeName>::operator-=(const Set<TypeName>& set) {
    for (size_t i = 0; i < set.GetLength(); i++) {
        this->Delete(set[i]);
    }

    return *this;
}

template<typename TypeName>
Set<TypeName>& Set<TypeName>::operator*=(const Set<TypeName>& set) {
    for (size_t i = 0; i < (*this).GetLength(); i++) {
        if (!set.isElement((*this)[i])) {
            this->Delete((*this)[i]);
        }
    }

    return *this;
}

template<typename TypeName>
bool Set<TypeName>::operator==(const Set<TypeName>& set) const {
    return Vector<TypeName>::operator==(set);
}

template<typename TypeName>
size_t Set<TypeName>::GetLength() const {
    return Vector<TypeName>::GetLength();
}

template<typename TypeName>
void Set<TypeName>::Add(TypeName value) {
    auto [isSuccess, index] = this->Find(value);

    if (isSuccess) {
        return;
    }

    this->Vector<TypeName>::Add(value);

    this->Sort();
}

template<typename TypeName>
void Set<TypeName>::Delete(TypeName value) {
    auto [isSuccess, index] = this->Find(value);

    if (!isSuccess) {
        return;
    }

    this->Vector<TypeName>::Delete(index);
}

template<typename TypeName>
bool Set<TypeName>::isElement(TypeName value) const {
    size_t low = 0;
    size_t high = this->GetLength() - 1;

    while (low <= high) {
        size_t mid = low + (high - low) / 2;

        if (this->EqualElements((*this)[mid], value)) {
            return true;
        }

        if (this->CompareElements((*this)[mid], value, true)) {
            low = mid + 1;
        } else {
            if (low == high) {
                return false;
            }

            high = mid - 1;
        }
    }

    return false;
}

template<typename TypeName>
std::ostream& operator<<(std::ostream& stream, const Set<TypeName>& set) {
    size_t length = set.GetLength();

    stream << '{';

    for (size_t i = 0; i < length; i++) {
        stream << set[i];

        if (i != length - 1) {
            std::cout << ", ";
        }
    }

    stream << '}';

    return stream;
}

template<typename TypeName>
Set<TypeName> operator+(const Set<TypeName>& firstSet, const Set<TypeName>& secondSet) {
    Set<TypeName> temp = firstSet;

    temp += secondSet;

    return temp;
}

template<typename TypeName>
Set<TypeName> operator-(const Set<TypeName>& firstSet, const Set<TypeName>& secondSet) {
    Set<TypeName> temp = firstSet;

    temp -= secondSet;

    return temp;
}

template<typename TypeName>
Set<TypeName> operator*(const Set<TypeName>& firstSet, const Set<TypeName>& secondSet) {
    Set<TypeName> temp = firstSet;

    temp *= secondSet;

    return temp;
}

#endif
