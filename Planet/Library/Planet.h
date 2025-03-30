#ifndef PLANET_H
#define PLANET_H

#include <cstddef>
#include <fstream>
#include <iostream>

class Planet {
 private:
    static size_t totalCount;
    size_t id = 0;

    char* name = nullptr;
    size_t nameLength = 0;
    size_t diameter = 0;
    bool lifeExists = 0;
    size_t satellitesCount = 0;

    void IdInit();
    void NameInit(const char* name);

    void Print(std::ofstream& stream);
    void Print(std::ostream& stream);

 public:
    Planet();
    Planet(Planet& planet);
    Planet(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount);
    ~Planet();

    Planet& operator=(const Planet& planet);

    bool operator==(const Planet& planet) const;
    bool operator>(const Planet& planet) const;
    bool operator<(const Planet& planet) const;

    friend std::ofstream& operator<<(std::ofstream& stream, Planet& planet);
    friend std::ifstream& operator>>(std::ifstream& stream, Planet& planet);

    friend std::ostream& operator<<(std::ostream& stream, Planet& planet);
    friend std::istream& operator>>(std::istream& stream, Planet& planet);
};

#endif
