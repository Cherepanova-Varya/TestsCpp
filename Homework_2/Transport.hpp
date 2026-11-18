#pragma once
#include "Inventory.hpp"

class Transport : public InventoryItem {
private:
	std::string Id;
	std::string Name;
	int Score;
public:
	Transport(std::string i, std::string n, int s);
  std::string inventoryId() const override;
	std::string name() const override;
	int score() const;
	bool SuitableForNovice() const override;
};

class Bike : public Transport {
public:
	Bike(std::string i, std::string n, int s);
	void describe() const override;
};

class EBike: public Transport, public EnergyConsumer {
private:
	double DailyEnergy;
public:
	EBike(std::string i, std::string n, double e, int s);
	double dailyEnergy() const override;
	void describe() const override;
};

class Scooter : public Transport, public EnergyConsumer {
private:
	double DailyEnergy;
public:
	Scooter(std::string i, std::string n, double e, int s);
	double dailyEnergy() const override;
	void describe() const override;
};