#include "Patient.h"

#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

using std::size_t;

namespace {
const size_t kBufferSize = 256;
}  // namespace

size_t Patient::totalCount = 0;

void Patient::IdInit() {
    ++this->totalCount;
    this->id = this->totalCount;
}

void Patient::NameInit(const char* name, size_t nameLength) {
    this->nameLength = nameLength;
    this->name = new char[this->nameLength];

    for (size_t i = 0; i < this->nameLength; i++) {
        this->name[i] = name[i];
    }
}

void Patient::NameSet(const char* name) {
    size_t newNameLength = strlen(name) + 1;

    if (this->nameLength != newNameLength) {
        delete[] this->name;
    }

    this->NameInit(name, newNameLength);
}

void Patient::CodeSet(const char* personalFileCode) {
    for (size_t i = 0; i < kPersonalFileCodeLength; i++) {
        this->personalFileCode[i] = personalFileCode[i];
    }
}

Patient::Patient() : personalFileCode(new char[kPersonalFileCodeLength]) {
    this->IdInit();
    this->CodeSet("000\0");

    std::cout << "Создание ID " << this->id << '\n';
};

Patient::Patient(Patient& patient) : age(patient.age) {
    size_t nameLength = strlen(patient.name) + 1;
    this->NameInit(patient.name, nameLength);
    this->CodeSet(patient.personalFileCode);

    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
}

Patient::Patient(const char* name, const char* personalFileCode, bool sex, size_t age) : sex(sex), age(age) {
    size_t nameLength = strlen(name) + 1;
    this->NameInit(name, nameLength);
    this->CodeSet(personalFileCode);

    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
}

Patient::~Patient() {
    delete[] this->name;
    delete[] this->personalFileCode;

    std::cout << "Удаление ID " << this->id << '\n';
}

Patient& Patient::operator=(const Patient& patient) {
    size_t nameLength = strlen(patient.name) + 1;
    this->NameInit(patient.name, nameLength);
    this->CodeSet(patient.personalFileCode);
    this->sex = patient.sex;
    this->age = patient.age;

    return *this;
}

bool Patient::operator==(const Patient& patient) const {
    return (strcmp(this->name, patient.name) == 0) && (strcmp(this->personalFileCode, patient.personalFileCode) == 0) && (this->sex == patient.sex) &&
           (this->age == patient.age);
}

bool Patient::operator<(const Patient& patient) const {
    return this->age < patient.age;
}

bool Patient::operator>(const Patient& patient) const {
    return patient < *this;
}

void Patient::Print() {
    std::cout << "Название: " << this->name << "; Код личного дела: " << this->personalFileCode << "; Пол: " << (this->sex ? "Мужской" : "Женский")
              << "; Возраст: " << this->age << ";\n";
}

std::ofstream& operator<<(std::ofstream& stream, Patient& patient) {
    stream << patient.name << ' ' << patient.personalFileCode << ' ' << patient.age << '\n';
    return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Patient& patient) {
    char name[kBufferSize]{'\0'};
    char personalFileCode[kPersonalFileCodeLength]{'\0'};
    size_t age = 0;

    stream >> name;
    stream >> personalFileCode;
    stream >> age;

    patient.NameSet(name);
    patient.CodeSet(personalFileCode);
    patient.age = age;
    return stream;
}
