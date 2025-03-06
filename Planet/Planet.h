#ifndef PLANET_H
#define PLANET_H

#include <cstddef>
#include <cstring>
#include <fstream>

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
    Planet(Planet& planet);
    Planet(const char* name, size_t diameter, bool lifeExists, size_t satellitesCount);
    ~Planet();

    Planet& operator=(const Planet& planet);

    bool operator==(const Planet& planet) const;
    bool operator>(const Planet& planet) const;
    bool operator<(const Planet& planet) const;

    size_t GetTotalCount() const;
    size_t GetId() const;
    char* GetName() const;
    size_t GetDiameter() const;
    bool GetLifeExists() const;
    size_t GetSatellitesCount() const;

    void SetName(const char* name);
    void SetDiameter(size_t diameter);
    void SetLifeExists(bool lifeExists);
    void SetSatellitesCount(size_t satellitesCount);

    void Print();

   friend std::ofstream& operator<<(std::ofstream& stream, Space::Planet& planet);
   friend std::ifstream& operator>>(std::ifstream& stream, Space::Planet& planet);
};

};  // namespace Space

// std::ofstream& operator<<(std::ofstream& stream, Space::Planet& planet);
// std::ifstream& operator>>(std::ifstream& stream, Space::Planet& planet);

#endif
