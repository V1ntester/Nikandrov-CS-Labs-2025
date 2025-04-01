#include <iostream>
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

    void Show(std::ostream& stream = std::cout) const override;

    Employee& operator=(const Employee& employee);

    friend std::istream& operator>>(std::istream& stream, Employee& employee);
};
