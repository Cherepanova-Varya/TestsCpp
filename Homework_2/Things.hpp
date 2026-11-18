#pragma once
#include "Inventory.hpp"


class Helmet : public InventoryItem {
private:
  std::string Id;
	std::string Name;
public:
	Helmet(std::string i, std::string n);
	std::string name() const override;
	std::string inventoryId() const override;
	void describe() const override;
};

class KneePads : public InventoryItem {
private:
	std::string Id;
	std::string Name;
public:
	KneePads(std::string i, std::string n);
	std::string name() const override;
	std::string inventoryId() const override;
	void describe() const override;
};

class Dock : public InventoryItem, public EnergyConsumer {
private:
  std::string Id;
	std::string Name;
	double DailyEnergy;
public:
	Dock(std::string i, std::string n, double e);
	std::string name() const override;
	std::string inventoryId() const override;
	double dailyEnergy() const override;
  void describe() const override;
};