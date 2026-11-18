#pragma once
#include <iostream>
#include <string>

class InventoryItem {
public:
	virtual std::string inventoryId() const = 0;
	virtual std::string name() const = 0;
	virtual void describe() const = 0;
	virtual bool SuitableForNovice() const;
	virtual double dailyEnergy() const;
	virtual ~InventoryItem() {}
};

std::ostream& operator<<(std::ostream& os, const InventoryItem& i);
bool operator<(const InventoryItem& a, const InventoryItem& b);

class EnergyConsumer {
public:
	virtual double dailyEnergy() const = 0;
	virtual ~EnergyConsumer() {}
};