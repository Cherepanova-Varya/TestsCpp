#include <iostream>
#include <cstring>

void deposit(int& now_balance) {
  int add{0};
  std::cin >> add;
  if (add > 0) {
    now_balance += add;
  } else {
    std::cout << "error" << "\n";
  }
}
void withdraw(int& now_balance) {
  int taken{0};
  std::cin >> taken;
  if (taken > 0 && now_balance - taken >= 0) {
    now_balance -= taken;
  } else {
    std::cout << "error" << "\n";
  }
}
void balance(int& now_balance) {
  std::cout << now_balance << "\n";
}
void reset(int& now_balance) {
  now_balance = 0;
}
void scholarship(int& now_balance) {
  now_balance += 7700;
}

int main() {
  int now_balance{0};
  char inst[][15]{
      "deposit",
      "withdraw",
      "balance",
      "reset",
      "scholarship",
  };
  void(*foo[])(int&) {
    deposit,
      withdraw,
      balance,
      reset,
      scholarship,
  };
  char now_inst[15];
  char end[15] = "stop";
  std::cin >> now_inst;
  while (std::strcmp(now_inst, end) != 0) {
    bool flag{false};
    for (int i = 0; i < sizeof(inst) / sizeof(inst[0]); ++i) {
      if (std::strcmp(inst[i], now_inst) == 0) {
        foo[i](now_balance);
        flag = true;
        break;
      }
    }
    if (!flag) {
      std::cout << "error" << "\n";
    }
    std::cin >> now_inst;
  }
  return 0;
}