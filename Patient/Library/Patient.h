#ifndef Patient_H
#define Patient_H

#include <cstddef>
#include <fstream>

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
    void NameInit(const char* name, size_t nameLength);

    void NameSet(const char* name);
    void CodeSet(const char* personalFileCode);

 public:
    Patient();
    Patient(Patient& Patient);
    Patient(const char* name, const char* personalFileCode, bool sex, size_t age);
    ~Patient();

    Patient& operator=(const Patient& patient);

    bool operator==(const Patient& patient) const;
    bool operator>(const Patient& patient) const;
    bool operator<(const Patient& patient) const;

    void Print();

    friend std::ofstream& operator<<(std::ofstream& stream, Patient& patient);
    friend std::ifstream& operator>>(std::ifstream& stream, Patient& patient);
};

#endif
