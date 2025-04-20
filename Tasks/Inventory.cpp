#include "Inventory.h"

#include <iostream>

Inventory::Inventory() = default;

Inventory::Inventory(std::string item, double cost, size_t onHand) : item(std::move(item)), cost(cost), onHand(onHand) {
}

Inventory::Inventory(const Inventory& inventory) = default;

Inventory& Inventory::operator=(const Inventory& inventory) = default;

bool Inventory::operator<(const Inventory& inventory) const {
    return this->cost < inventory.cost;
}

bool Inventory::operator>(const Inventory& inventory) const {
    return inventory < *this;
}

bool Inventory::operator==(const Inventory& inventory) const {
    return (this->item == inventory.item) && (this->cost == inventory.cost) && (this->onHand == inventory.onHand);
}

size_t Inventory::GetOnHand() const {
    return this->onHand;
}

std::ostream& operator<<(std::ostream& stream, const Inventory& inventory) {
    stream << inventory.item << " - " << inventory.cost << " - " << inventory.onHand;
    return stream;
}
