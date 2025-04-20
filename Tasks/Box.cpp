#include "Box.h"

Box::Box() = default;

Box::Box(double a, double b, double c) : a(a), b(b), c(c) {
}

Box::Box(const Box& box) = default;

Box& Box::operator=(const Box& box) = default;

bool Box::operator<(const Box& box) const {
    return (this->a * this->b * this->c) < (box.a * box.b * box.c);
}

std::ostream& operator<<(std::ostream& stream, const Box& box) {
    stream << box.a << '\n' << box.b << '\n' << box.c << '\n';
    return stream;
}
