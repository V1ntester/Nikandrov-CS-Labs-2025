#include <iostream>
#include "Person.h"

class Engineer : public Person {
 protected:
    double analyticalThinking = 0.0;
    double communicationSkills = 0.0;

 public:
    Engineer();
    Engineer(const char* name, size_t salary, double efficiency, double teamWork, double analyticalThinking, double communicationSkills);
    Engineer(const Engineer& engineer);

    ~Engineer() override;

    void Show(std::ostream& stream = std::cout) const override;

    Engineer& operator=(const Engineer& engineer);

    friend std::istream& operator>>(std::istream& stream, Engineer& engineer);
};
