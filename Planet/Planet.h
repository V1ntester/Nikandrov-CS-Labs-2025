#include <cstddef>

class Planet {
 private:
    char* name = nullptr;
    size_t diameter = 0;
    size_t population = 0;
    size_t satellitesCount = 0;

 public:
    Planet(char* name, size_t diameter, size_t population, size_t satellitesCount);
    ~Planet();

    char* GetName();
    size_t GetDiameter();
    size_t GetPopulation();
    size_t GetSatellitesCount();
    void SetName(char* name);
    void SetDiameter(size_t diameter);
    void SetPopulation(size_t population);
    void SetSatellitesCount(size_t satellitesCount);

    void Print();
};
