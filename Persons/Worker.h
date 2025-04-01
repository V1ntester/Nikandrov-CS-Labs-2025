#include "Person.h"

class Worker : public Person {
 protected:
    double stamina = 0.0;
    double discipline = 0.0;

 public:
    Worker();
    Worker(const char* name, size_t salary, double efficiency, double teamWork, double stamina, double discipline);
    Worker(const Worker& worker);

    ~Worker() override;

    void Show() const override;

    Worker& operator=(const Worker& worker);
};
