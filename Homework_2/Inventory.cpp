#include <string>
#include "Inventory.hpp"

bool InventoryItem::SuitableForNovice() const {
	return false;
}
double InventoryItem::dailyEnergy() const {
	return 0;
}

std::ostream& operator<<(std::ostream& os, const InventoryItem& i) {
	os << i.inventoryId() << " " << i.name();
	return os;
}

bool operator<(const InventoryItem& a, const InventoryItem& b) {
	return a.inventoryId() < b.inventoryId();
}