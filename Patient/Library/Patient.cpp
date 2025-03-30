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

void Patient::NameInit(const char* name) {
    size_t newNameLength = strlen(name) + 1;

    if (this->nameLength != newNameLength) {
        char* newName = new char[newNameLength];

        strncpy(newName, name, newNameLength);

        delete[] this->name;

        this->name = newName;

        this->nameLength = newNameLength;
    } else {
        strncpy(this->name, name, newNameLength);
    }
}

void Patient::CodeInit(const char* personalFileCode) {
    for (size_t i = 0; i < kPersonalFileCodeLength; i++) {
        this->personalFileCode[i] = personalFileCode[i];
    }
}

void Patient::Print(std::ofstream& stream) {
    stream << this->name << ' ' << this->personalFileCode << ' ' << this->age << '\n';
}

void Patient::Print(std::ostream& stream) {
    stream << "Название: " << this->name << "; Код личного дела: " << this->personalFileCode << "; Пол: " << (this->sex ? "Мужской" : "Женский")
           << "; Возраст: " << this->age << ";\n";
}

Patient::Patient() : personalFileCode(new char[kPersonalFileCodeLength]) {
    this->IdInit();
    this->CodeInit("000\0");

    std::cout << "Создание ID " << this->id << '\n';
};

Patient::Patient(Patient& patient) : age(patient.age) {
    this->NameInit(patient.name);
    this->CodeInit(patient.personalFileCode);

    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
}

Patient::Patient(const char* name, const char* personalFileCode, bool sex, size_t age) : sex(sex), age(age) {
    this->NameInit(name);
    this->CodeInit(personalFileCode);

    this->IdInit();

    std::cout << "Создание ID " << this->id << '\n';
}

Patient::~Patient() {
    delete[] this->name;
    delete[] this->personalFileCode;

    std::cout << "Удаление ID " << this->id << '\n';
}

Patient& Patient::operator=(const Patient& patient) {
    this->NameInit(patient.name);
    this->CodeInit(patient.personalFileCode);
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

std::ofstream& operator<<(std::ofstream& stream, Patient& patient) {
    patient.Print(stream);

    return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Patient& patient) {
    char name[kBufferSize]{'\0'};
    char personalFileCode[kPersonalFileCodeLength]{'\0'};
    size_t age = 0;
    bool sex = false;

    stream >> name;
    stream >> personalFileCode;
    stream >> age;
    stream >> sex;

    patient.NameInit(name);
    patient.CodeInit(personalFileCode);
    patient.age = age;
    patient.sex = sex;

    return stream;
}

std::ostream& operator<<(std::ostream& stream, Patient& patient) {
    patient.Print(stream);

    return stream;
}

std::istream& operator>>(std::istream& stream, Patient& patient) {
    char name[kBufferSize]{'\0'};
    char personalFileCode[kPersonalFileCodeLength]{'\0'};
    size_t age = 0;
    bool sex = false;

    std::cout << "Введите имя: ";
    stream >> name;

    std::cout << "Введите код: ";
    stream >> personalFileCode;

    std::cout << "Введите возраст: ";
    stream >> age;

    std::cout << "Введите пол (1 - мужской; 0 - женский): ";
    stream >> sex;

    patient.NameInit(name);
    patient.CodeInit(personalFileCode);
    patient.age = age;
    patient.sex = sex;

    return stream;
}
