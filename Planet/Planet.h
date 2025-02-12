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

    void Print();
};
