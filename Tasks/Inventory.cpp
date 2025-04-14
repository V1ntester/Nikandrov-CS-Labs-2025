#include "Inventory.h"

Inventory::Inventory() = default;

Inventory::Inventory(std::string item, double cost, size_t onHand) : item(item), cost(cost), onHand(onHand) {
}

Inventory::Inventory(const Inventory& inventory) = default;

Inventory& Inventory::operator=(const Inventory& inventory) {
    this->item = inventory.item;
    this->cost = inventory.cost;
    this->onHand = onHand;
}

bool Inventory::operator<(const Inventory& inventory) const {
    return this->cost < inventory.cost;
}

bool Inventory::operator>(const Inventory& inventory) const {
    return  inventory < *this;
}

bool Inventory::operator==(const Inventory& inventory) const {
    return (!(*this <  inventory) && !(inventory < * this));
}
