#include <iostream>
#include <string>
#include <utility>

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
    std::pair<std::string, void(*)(int&)> inst[] = {
        {"deposit", deposit},
        {"withdraw", withdraw},
        {"balance", balance},
        {"reset", reset},
        {"scholarship", scholarship}
    };
    std::string now_inst{""};
    std::cin >> now_inst;
    while (now_inst != "stop") {
        bool flag{false};
        for (int i = 0; i < sizeof(inst) / sizeof(inst[0]); ++i) {
            if (inst[i].first == now_inst) {
                inst[i].second(now_balance);
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