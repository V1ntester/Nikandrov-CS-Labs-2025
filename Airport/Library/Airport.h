#ifndef AIRPORT_H
#define AIRPORT_H

#include <cstddef>
#include <fstream>

class Airport {
 private:
    static size_t totalCount;
    size_t id = 0;

    char* name = nullptr;
    size_t nameLength = 0;
    char code[4] {'\0'};
    size_t runwaysCount = 0;

    void IdInit();
    void NameInit(const char* name, size_t nameLength);

    void NameSet(const char* name);
    void CodeSet(const char* code);

 public:
    Airport();
    Airport(Airport& airport);
    Airport(const char* name, const char code[4], size_t runwaysCount);
    ~Airport();

    Airport& operator=(const Airport& airport);

    bool operator==(const Airport& airport) const;
    bool operator>(const Airport& airport) const;
    bool operator<(const Airport& airport) const;

    void Print();

    friend std::ofstream& operator<<(std::ofstream& stream, Airport& airport);
    friend std::ifstream& operator>>(std::ifstream& stream, Airport& airport);
};

#endif
