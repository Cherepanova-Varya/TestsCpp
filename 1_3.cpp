#include <iostream>
#include <cstring>

void clear(char(&table)[5][10]) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      table[i][j] = ' ';
    }
  }
}

bool put(char(&table)[5][10], int x, int y, char c) {
  if (x >= 0 && y >= 0 && x < 10 && y < 5) {
    table[y][x] = c;
    return true;
  }
  return false;
}

bool text(char(&table)[5][10], int x, int y, char w[15]) {
  if (y >= 0 && y < 5 && x >= 0 && x + std::strlen(w) - 1 < 10) {
    for (int i = x; i < x + std::strlen(w); ++i) {
      table[y][i] = w[i - x];
    }
    return true;
  }
  return false;
}

void print(char(&table)[5][10]) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << table[i][j];
    }
    std::cout << "\n";
  }
}

int main() {
  char table[5][10];
  clear(table);
  char command[15];
  std::cin >> command;
  while (std::strcmp(command, "quit") != 0) {
    if (std::strcmp(command, "clear") == 0) {
      clear(table);
    } else if (std::strcmp(command, "put") == 0) {
      int x{0};
      int y{0};
      char c{'0'};
      std::cin >> x >> y >> c;
      if (!put(table, x, y, c)) {
        std::cout << "error" << "\n";
      }
    } else if (std::strcmp(command, "text") == 0) {
      int x{0};
      int y{0};
      char w[15];
      std::cin >> x >> y >> w;
      if (!text(table, x, y, w)) {
        std::cout << "error" << "\n";
      }
    } else {
      print(table);
    }
    std::cin >> command;
  }
  return 0;
}