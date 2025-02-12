#ifndef PLANET_H
#define PLANET_H

#include <cstddef>

class Planet {
 private:
    size_t id = 0;
    char* name = nullptr;
    size_t nameLength = 0;
    size_t diameter = 0;
    size_t population = 0;
    size_t satellitesCount = 0;

    void InitName(const char* name, size_t nameLength);

 public:
    Planet(const char* name, size_t diameter, size_t population, size_t satellitesCount);
    Planet(size_t id, const char* name, size_t diameter, size_t population, size_t satellitesCount);
    ~Planet();

    size_t GetId();
    char* GetName();
    size_t GetDiameter();
    size_t GetPopulation();
    size_t GetSatellitesCount();
    void SetName(const char* name);
    void SetDiameter(size_t diameter);
    void SetPopulation(size_t population);
    void SetSatellitesCount(size_t satellitesCount);

    void Print();
};

#endif
