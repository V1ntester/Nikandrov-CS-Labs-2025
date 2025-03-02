#ifndef PLANET_H
#define PLANET_H

#include <cstddef>
#include <fstream>

namespace Space {

class Planet {
 private:
    static size_t totalCount;
    bool service = false;
    size_t id = 0;
    char* name = nullptr;
    size_t nameLength = 0;
    size_t diameter = 0;
    bool lifeExists = 0;
    size_t satellitesCount = 0;

    void InitId();
    void InitName(const char* name, size_t nameLength);

 public:
    Planet(bool service = false);
    Planet(Planet& planet, bool service = false);
    Planet(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount, bool service = false);
    ~Planet();

    Planet& operator=(const Planet& planet);

    size_t GetTotalCount();
    size_t GetId();
    char* GetName();
    size_t GetNameLength();
    size_t GetDiameter();
    bool GetLifeExists();
    size_t GetSatellitesCount();

    void SetTotalCount(size_t totalCount);
    void SetName(const char* name);
    void SetDiameter(size_t diameter);
    void SetLifeExists(bool lifeExists);
    void SetSatellitesCount(size_t satellitesCount);

    void Print();
};

};  // namespace Space

std::ofstream& operator<<(std::ofstream& stream, Space::Planet& planet);
std::ifstream& operator>>(std::ifstream& stream, Space::Planet& planet);

#endif
