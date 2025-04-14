#pragma once

#include <cstddef>
#include <string>

class Inventory {
    private:
        std::string item;
        double cost = 0;
        size_t onHand = 0;

    public:
        Inventory();
        Inventory(std::string item, double cost, size_t onHand);
        Inventory(const Inventory& inventory);

        Inventory& operator=(const Inventory& inventory);

        bool operator<(const Inventory& inventory) const;
        bool operator>(const Inventory& inventory) const;
        bool operator==(const Inventory& inventory) const;
};
