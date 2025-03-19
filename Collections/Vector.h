#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>

namespace {
    struct FindAnswer {
        bool isSuccess = false;
        size_t index = 0;
    };
}

template <typename typeName>
class Vector {
    private:
        size_t filled = 0;
        size_t length = 0;

        typeName* data = nullptr;

        void Resize(size_t length) {

        }

        void Copy(const typeName& vector) {
            typeName newData = new typeName[]

            if (data) {
                delete[] data;
            }
        }

    public:
        Vector() = default;
        Vector(typeName value) {
            this->Add(value);
        }

        Vector(const Vector& vector) {

        }

        Vector& operator=(const Vector& vector) {
            this->Copy(vector);
        }

        typeName operator[](unsigned index) {
            if (index < 0 || index >= filled) {
                throw std::out_of_range("Index  out of range");
            }

            return this->data[index];
        }

        void Add(typeName value) {
            if (this->filled == this->length) {
                this->Resize(this->length * 2);

                this->length*=2;
            }

            this->data[filled] = value;

            ++this->filled;
        }

        void Delete(size_t index) {
            for (size_t i = index + 1; i < filled; i++) {
                
            }

            --this->filled;

            if (this->filled == this->length/4) {
                this->Resize(this->length/2);
                
                this->length/=2;
            }
        }

        auto Find(typeName value) const {
            bool isSucess = false;
            size_t index = 0;

            return FindAnswer(isSucess, index);
        }
};

#endif
