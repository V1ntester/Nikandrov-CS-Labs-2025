#include "Person.h"

class Employee : public Person {
 protected:
    double stressResistance = 0.0;
    double initiative = 0.0;

 public:
    Employee();
    Employee(const char* name, size_t salary, double efficiency, double teamWork, double stressResistance, double initiative);
    Employee(const Employee& employee);

    ~Employee() override;

    void Show() const override;

    Employee& operator=(const Employee& employee);
};
