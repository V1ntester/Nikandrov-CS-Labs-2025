#pragma once

#include <iostream>

class Box {
 public:
    Box();
    Box(double a, double b, double c);
    Box(const Box& box);

    Box& operator=(const Box& box);

    bool operator<(const Box& box) const;

    friend std::ostream& operator<<(std::ostream& stream, const Box& box);

 private:
    double a = 0;
    double b = 0;
    double c = 0;
};
