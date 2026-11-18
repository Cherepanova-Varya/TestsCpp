#include <iostream>
#include "Things.hpp"
#include "Inventory.hpp"
#include "Errors.hpp"

Helmet::Helmet(std::string i, std::string n): Id(i), Name(n) {
  if (i.empty()) {
    throw ArgumentError("empty ID");
  }
}

std::string Helmet::name() const { return Name; }
std::string Helmet::inventoryId() const { return Id; }
void Helmet::describe() const {
  std::cout << "Type: Thing/Helmet:" << "\n";
  std::cout << "    Name: " << name() << "\n";
  std::cout << "    ID: " << inventoryId() << "\n" << "\n";
}

KneePads::KneePads(std::string i, std::string n): Id(i), Name(n) {
  if (i.empty()) {
    throw ArgumentError("empty ID");
  }
}

std::string KneePads::name() const { return Name; }
std::string KneePads::inventoryId() const { return Id; }
void KneePads::describe() const {
  std::cout << "Type: Thing/KneePads:" << "\n";
  std::cout << "    Name: " << name() << "\n";
  std::cout << "    ID: " << inventoryId() << "\n" << "\n";
}

Dock::Dock(std::string i, std::string n, double e): Id(i), Name(n), DailyEnergy(e) {
  if (i.empty()) {
    throw ArgumentError("empty ID");
  }
  if (e < 0) {
    throw ArgumentError("negative energy");
  }
}

std::string Dock::name() const { return Name; }
std::string Dock::inventoryId() const { return Id; }
double Dock::dailyEnergy() const { return DailyEnergy; }
void Dock::describe() const {
  std::cout << "Type: Thing/Dock:" << "\n";
  std::cout << "    Name: " << name() << "\n";
  std::cout << "    ID: " << inventoryId() << "\n";
  std::cout << "    DailyEnergy: " << dailyEnergy() << "\n" << "\n";
}