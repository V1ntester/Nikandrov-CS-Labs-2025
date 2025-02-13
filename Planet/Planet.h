#ifndef PLANET_H
#define PLANET_H

#include <cstddef>

namespace Space {
class Planet {
 private:
    static size_t totalCount;
    size_t id = 0;
    char* name = nullptr;
    size_t nameLength = 0;
    size_t diameter = 0;
    bool lifeExists = 0;
    size_t satellitesCount = 0;

    void InitId();
    void InitName(const char* name, size_t nameLength);

 public:
    Planet();
    Planet(const char* name, size_t diameter, size_t population, size_t satellitesCount);
    ~Planet();

    Planet& operator=(const Planet& planet);

    size_t GetId();
    char* GetName();
    size_t GetNameLength();
    size_t GetDiameter();
    bool GetLifeExists();
    size_t GetSatellitesCount();
    void SetName(const char* name);
    void SetDiameter(size_t diameter);
    void SetLifeExists(bool lifeExists);
    void SetSatellitesCount(size_t satellitesCount);

    void Print();
};
}  // namespace Space

#endif
