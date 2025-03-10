#ifndef PLANET_H
#define PLANET_H

#include <cstddef>
#include <fstream>

class Airport {
 private:
    static size_t totalCount;
    size_t id = 0;

    char* name = nullptr;
    size_t nameLength = 0;
    size_t diameter = 0;
    bool lifeExists = 0;
    size_t satellitesCount = 0;

    void IdInit();
    void NameInit(const char* name, size_t nameLength);

    void NameSet(const char* name);

 public:
    Airport();
    Airport(Airport& planet);
    Airport(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount);
    ~Airport();

    Airport& operator=(const Airport& planet);

    bool operator==(const Airport& planet) const;
    bool operator>(const Airport& planet) const;
    bool operator<(const Airport& planet) const;

    void Print();

    friend std::ofstream& operator<<(std::ofstream& stream, Airport& planet);
    friend std::ifstream& operator>>(std::ifstream& stream, Airport& planet);
};

#endif
