#include <iostream>
#include "Errors.hpp"
#include "Transport.hpp"
#include "Inventory.hpp"

Transport::Transport(std::string i, std::string n, int s): Id(i), Name(n), Score(s) {
  if (i.empty()) {
    throw ArgumentError("empty ID");
  }
  if (s < 1 || s > 10) {
    throw ArgumentError("score must be 1..10");
  }
}

std::string Transport::name() const { return Name; }
std::string Transport::inventoryId() const { return Id; }
int Transport::score() const { return Score; }
bool Transport::SuitableForNovice() const { return Score >= 6; }

Bike::Bike(std::string i, std::string n, int s): Transport(i, n, s) {}

void Bike::describe() const {
  std::cout << "Type: Transport/Bike:" << "\n";
  std::cout << "    Name: " << name() << "\n";
  std::cout << "    ID: " << inventoryId() << "\n";
  std::cout << "    Score for novice: " << score() << "\n";
  if (SuitableForNovice()) {
    std::cout << "    Suitable for novice" << "\n" << "\n";
  } else {
    std::cout << "    Only for pros" << "\n" << "\n";
  }
}

EBike::EBike(std::string i, std::string n, double e, int s): Transport(i, n, s), DailyEnergy(e) {
  if (e < 0) {
    throw ArgumentError("negative energy");
  }
}

double EBike::dailyEnergy() const { return DailyEnergy; }
void EBike::describe() const {
  std::cout << "Type: Transport/EBike:" << "\n";
  std::cout << "    Name: " << name() << "\n";
  std::cout << "    ID: " << inventoryId() << "\n";
  std::cout << "    DailyEnergy: " << dailyEnergy() << "\n";
  std::cout << "    Score for novice: " << score() << "\n";
  if (SuitableForNovice()) {
    std::cout << "    Suitable for novice" << "\n" << "\n";
  } else {
    std::cout << "    Only for pros" << "\n" << "\n";
  }
}

Scooter::Scooter(std::string i, std::string n, double e, int s): Transport(i, n, s), DailyEnergy(e) {
  if (e < 0) {
    throw ArgumentError("negative energy");
  }
}

double Scooter::dailyEnergy() const { return DailyEnergy; }
void Scooter::describe() const {
  std::cout << "Type: Transport/Scooter:" << "\n";
  std::cout << "    Name: " << name() << "\n";
  std::cout << "    ID: " << inventoryId() << "\n";
  std::cout << "    DailyEnergy: " << dailyEnergy() << "\n";
  std::cout << "    Score for novice: " << score() << "\n";
  if (SuitableForNovice()) {
    std::cout << "    Suitable for novice" << "\n" << "\n";
  } else {
    std::cout << "    Only for pros" << "\n" << "\n";
  }
}