#pragma once
#include <iostream>
#include "Errors.hpp"

template <typename T, int Cap>
class Registry {
private:
	T List[Cap];
	int N = 0;
public:
	bool add(const T& x) {
	  if (N >= Cap) {
			return false;
		} else {
			List[N] = x;
			++N;
			return true;
		}
	}
	int size() const { return N; }
	const T& operator[](int i) const {
	  if (i < 0 || i >= N) {
			throw ArgumentError("bad index");
		}
		return List[i];
	}
};

template <typename T, int Cap>
std::ostream& operator<<(std::ostream& os, const Registry<T, Cap>& r) {
	for (int i = 0; i < static_cast<int>(r.size()); ++i) {
		os << r[i] << "\n";
	}
	return os;
}