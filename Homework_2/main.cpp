#include "Inventory.hpp"
#include "Things.hpp"
#include "Transport.hpp"
#include "Errors.hpp"
#include "Registry.hpp"
#include "ServiceCenter.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

int FindById(const std::vector<std::shared_ptr<InventoryItem>>& park, const std::string& id) {
	for (int i = 0; i < static_cast<int>(park.size()); ++i) {
	  if (park[i]->inventoryId() == id) {
			return i;
		}
	}
	return -1;
}

void Remove(std::vector<std::shared_ptr<InventoryItem>>& park, const std::string& id, Registry<std::string, 10>& removedItems) {
	int ind = FindById(park, id);
	if (ind == -1) {
		throw NotFoundError("item not found");
	} else {
		auto now = park[ind]->inventoryId();
    park.erase(park.begin() + ind);
		if (!removedItems.add(now)) {
			throw ArgumentError("too many remote devices");
		}
	}
}

template <typename Case>
double Energy(const Case& v) {
	double sum{0.0};
	for (const auto& p : v) {
		sum += p->dailyEnergy();
	}
	return sum;
}

void Novice(const std::vector<std::shared_ptr<InventoryItem>>& park) {
  for (const auto& p : park) {
	  if (p->SuitableForNovice()) {
			std::cout << *p << "\n";
		}
	}
}

void List(std::vector<std::shared_ptr<InventoryItem>>& park) {
	std::sort(park.begin(), park.end(), [](const auto& a, const auto& b) { return *a < *b; });
	for (const auto& p : park) {
		std::cout << *p << "\n";
	}
}

void addTransport(std::vector<std::shared_ptr<InventoryItem>>& park, const ServiceCenter& service, std::unique_ptr<Transport> item) {
  if (FindById(park, item->inventoryId()) != -1) {
		throw ArgumentError("duplicate ID");
	}
	service.inspect(*item);
	park.push_back(std::move(item));
}

void addThing(std::vector<std::shared_ptr<InventoryItem>>& park, std::unique_ptr<InventoryItem> item) {
	if (FindById(park, item->inventoryId()) != -1) {
		throw ArgumentError("duplicate ID");
	}
	park.push_back(std::move(item));
}

int main() {
	ServiceCenter service;
	std::vector<std::shared_ptr<InventoryItem>> park;
	std::weak_ptr<InventoryItem> display;
	Registry<std::string, 10> removedItems;
	Registry<std::weak_ptr<InventoryItem>, 100> favourite;
	
	std::string command{""};
	std::cin >> command;
	while (command != "quit") {
		try {
			if (command == "add") {
				std::string item{""};
				std::cin >> item;
				if (item == "scooter") {
					std::string id;
					std::string name;
					double energy;
					int score;
					std::cin >> id >> name >> energy >> score;
					addTransport(park, service, std::make_unique<Scooter>(id, name, energy, score));
				} else if (item == "bike") {
					std::string id;
					std::string name;
					int score;
					std::cin >> id >> name >> score;
					addTransport(park, service, std::make_unique<Bike>(id, name, score));
				} else if (item == "ebike") {
					std::string id;
					std::string name;
					double energy;
					int score;
					std::cin >> id >> name >> energy >> score;
					addTransport(park, service, std::make_unique<EBike>(id, name, energy, score));
				} else if (item == "helmet") {
					std::string id;
					std::string name;
					std::cin >> id >> name;
					addThing(park, std::make_unique<Helmet>(id, name));
				} else if (item == "kneepads") {
					std::string id;
					std::string name;
					std::cin >> id >> name;
					addThing(park, std::make_unique<KneePads>(id, name));
				} else if (item == "dock") {
					std::string id;
					std::string name;
					double energy;
					std::cin >> id >> name >> energy;
					addThing(park, std::make_unique<Dock>(id, name, energy));
				} else {
					throw ArgumentError("unknown item");
				}
			} else if (command == "energy") {
				std::cout << std::fixed << std::setprecision(1) << Energy(park) << "\n";
			} else if (command == "novice") {
				Novice(park);
			} else if (command == "list") {
				List(park);
			} else if (command == "remove") {
				std::string id{""};
				std::cin >> id;
				Remove(park, id, removedItems);
			} else if (command == "removed") {
				std::cout << removedItems;
			} else if (command == "focus") {
				std::string id;
				std::cin >> id;
				int ind = FindById(park, id);
				if (ind == -1) {
					throw NotFoundError("item not found");
				}
				display = park[ind];
			} else if (command == "show_focus") {
				if (auto i = display.lock()) {
					std::cout << *i << "\n";
				} else {
					std::cout << "removed" << "\n";
				}
			} else if (command == "favourite") {
				std::string id;
				std::cin >> id;
				int ind = FindById(park, id);
				if (ind == -1) {
					throw NotFoundError("item not found");
				}
				if (!favourite.add(park[ind])) {
					throw ArgumentError("list of favourites is full");
				}
			} else if (command == "my_favourites") {
				for (int i = 0; i < static_cast<int>(favourite.size()); ++i) {
				  if (auto s = favourite[i].lock()) {
						s->describe();
					} else {
						std::cout << "removed" << "\n";
					}
				}
			} else {
				throw ArgumentError("unknown command");
			}
		} catch(const FleetError& e) {
			std::cout << "error: " << e.what() << "\n";
		}
		std::cin >> command;
	}
}