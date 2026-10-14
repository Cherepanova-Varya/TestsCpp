#include <iostream>
#include <string>

// Заполняем классный журнал. Информация хранится в двух массивах: посещаемость - в visiting, отметки - в grades;
// Если ученик на уроке не присутствовал, вместо отметки записываем причину отсутствия: Б, УП, НП, ...
// Оценки храним типом int, чтобы в будущем можно было считать некие параметры: средний балл, сумму и т.д.
// Тогда в массиве должны быть разные типы данных. Поэтому создаём массив указателей (массив grades) типа void, тип которых определяем по
// массиву visiting при разыменовывании при выводе журнала. Массив visiting - массив int. Для его заведения через new/delete как раз 
// требуется тройной указатель ***int. Таким образом все условия задачи выполнены.

int main() {
  int classes{0};
  int students{0};
  int lessons{0};
  std::cout << "The amount of classes, lessons and students: " << "\n";
  std::cin >> classes >> students >> lessons;

  int*** visiting = new int** [classes];
  void**** grades = new void*** [classes];
  for (int i = 0; i < classes; ++i) {
    visiting[i] = new int* [students];
    grades[i] = new void** [students];
    for (int j = 0; j < students; ++j) {
      visiting[i][j] = new int[lessons];
      grades[i][j] = new void*[lessons];
      for (int k = 0; k < lessons; ++k) {
        visiting[i][j][k] = 0;
        grades[i][j][k] = nullptr;
      }
    }
  }

  while (true) {
    int cl{0};
    std::cout << "Your class number in the system (or -1 if you want to complete): ";
    std::cin >> cl;

    if (cl == -1) {
      break;
    }

    int st{0};
    std::cout << "The number of the student in system: ";
    std::cin >> st;
    int les{0};
    std::cout << "The ordinal number of the lesson to be filled in: ";
    std::cin >> les;
    std::string visit{""};
    std::cout << "Was the student in the lesson (present/absent): ";
    std::cin >> visit;

    void* data = nullptr;

    if (visit == "present") {
      int grade;
      std::cout << "The grade of a student: ";
      std::cin >> grade;
      visiting[cl][st][les] = 1;
      data = new int(grade);
    }
    if (visit == "absent") {
      std::string reason;
      std::cout << "The reason of absent: ";
      std::cin >> reason;
      visiting[cl][st][les] = -1;
      data = new std::string(reason);
    }
    grades[cl][st][les] = data;
  }

  std::cout << "What class do you want to see? ";
  int show{0};
  std::cin >> show;

  std::cout << "\nClass journal: " << show << ":\n\n";

  std::cout << "       ";
  for (int i = 0; i < lessons; ++i) {
    std::cout << "Lesson " << i << "    ";
  }
  std::cout << "\n";
  for (int j = 0; j < students; ++j) {
    std::cout << "St " << j << "    ";
    for (int k = 0; k < lessons; ++k) {
      if (visiting[show][j][k] == 1) {
        std::cout << *static_cast<int*>(grades[show][j][k]) << "           ";
      } else if (visiting[show][j][k] == -1) {
        std::cout << *static_cast<std::string*>(grades[show][j][k]) << "           ";
      } else {
        std::cout << "-" << "           ";
      }
    }
    std::cout << "\n";
  }

  for (int i = 0; i < classes; ++i) {
    for (int j = 0; j < students; ++j) {
      for (int k = 0; k < lessons; ++k) {
        if (visiting[i][j][k] == 1) {
          delete static_cast<int*>(grades[i][j][k]);
        } else if (visiting[i][j][k] == -1) {
          delete static_cast<std::string*>(grades[i][j][k]);
        }
      }
      delete[] grades[i][j];
      delete[] visiting[i][j];
    }
    delete[] grades[i];
    delete[] visiting[i];
  }
  delete[] grades;
  delete[] visiting;

  return 0;
}