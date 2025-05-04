#pragma once

#include <cstddef>
#include <ostream>
#include <string>

class Inventory {
 public:
    Inventory();
    Inventory(std::string item, double cost, size_t onHand);
    Inventory(const Inventory& inventory);

    Inventory& operator=(const Inventory& inventory);

    bool operator<(const Inventory& inventory) const;
    bool operator>(const Inventory& inventory) const;
    bool operator==(const Inventory& inventory) const;

    size_t GetOnHand() const;

    friend std::ostream& operator<<(std::ostream& stream, const Inventory& inventory);

 private:
    std::string item;
    double cost = 0;
    size_t onHand = 0;
};
