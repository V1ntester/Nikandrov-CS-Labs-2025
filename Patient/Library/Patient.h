#ifndef Patient_H
#define Patient_H

#include <cstddef>
#include <fstream>
#include <iostream>

namespace {
const size_t kPersonalFileCodeLength = 4;
}

class Patient {
 private:
    static size_t totalCount;
    size_t id = 0;

    char* name = nullptr;
    size_t nameLength = 0;

    char* personalFileCode = nullptr;

    bool sex = true;
    size_t age = 0;

    void IdInit();
    void NameInit(const char* name);
    void CodeInit(const char* personalFileCode);

    void Print(std::ofstream& stream);
    void Print(std::ostream& stream);

 public:
    Patient();
    Patient(Patient& Patient);
    Patient(const char* name, const char* personalFileCode, bool sex, size_t age);
    ~Patient();

    Patient& operator=(const Patient& patient);

    bool operator==(const Patient& patient) const;
    bool operator>(const Patient& patient) const;
    bool operator<(const Patient& patient) const;

    friend std::ofstream& operator<<(std::ofstream& stream, Patient& patient);
    friend std::ifstream& operator>>(std::ifstream& stream, Patient& patient);

    friend std::ostream& operator<<(std::ostream& stream, Patient& patient);
    friend std::istream& operator>>(std::istream& stream, Patient& patient);
};

#endif
