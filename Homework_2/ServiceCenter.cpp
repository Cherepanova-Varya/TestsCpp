#include <cctype>
#include <string>
#include "Errors.hpp"
#include "ServiceCenter.hpp"

void ServiceCenter::inspect(const Transport& t) const {
  std::string n_copy = t.name();
  for (auto& c : n_copy) {
    if (isupper(c)) {
      c = (char) (c + 'a' - 'A');
    }
  }
  int x = n_copy.find("broken");
  if (x != -1) {
    throw RejectError("inspection rejected");
  }
}