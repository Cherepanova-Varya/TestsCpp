#pragma once
#include <string>
#include "Transport.hpp"

class ServiceCenter {
public:
	void inspect(const Transport& t) const;
};