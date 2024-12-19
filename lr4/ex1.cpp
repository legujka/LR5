#include <iostream>
#include <stdexcept>
#include <vector>

// Базовый класс для ошибок
class Error {
public:
  virtual void display() const = 0; // Виртуальный метод для вывода информации
  virtual ~Error() = default;
};

// Конкретные ошибки
class MemoryAccessError : public Error {
public:
  void display() const override {
    std::cout << "Memory Access Error" << std::endl;
  }
};

class MathError : public Error {
public:
  void display() const override {
    std::cout << "Math Error" << std::endl;
  }
};

class DivisionByZeroError : public Error {
public:
  void display() const override {
    std::cout << "Division by Zero Error" << std::endl;
  }
};

class OverflowError : public Error {
public:
  void display() const override {
    std::cout << "Overflow Error" << std::endl;
  }
};

// Шаблонный класс для хранения массива указателей
template <typename T>
class PointerArray {
private:
  std::vector<T*> data;

public:
  PointerArray() = default;

  // Добавление элемента
  void add(T* item) {
    data.push_back(item);
  }

  // Перегрузка оператора []
  T& operator[](size_t index) {
    if (index >= data.size()) {
      throw std::range_error("Index out of bounds");
    }
    return *data[index];
  }

  // Вывод всех элементов
  void displayAll() const {
    for (const auto& item : data) {
      item->display();
    }
  }

  // Деструктор
  ~PointerArray() {
    for (auto& item : data) {
      delete item;
    }
    data.clear();
  }
};

// Тестирование программы
int main() {
  try {
    // Создание массива ошибок
    PointerArray<Error> errors;

    // Добавление различных ошибок
    errors.add(new MemoryAccessError());
    errors.add(new MathError());
    errors.add(new DivisionByZeroError());
    errors.add(new OverflowError());

    // Вывод всех ошибок
    std::cout << "All errors:" << std::endl;
    errors.displayAll();

    // Попытка обратиться к несуществующему индексу
    std::cout << "Accessing an invalid index:" << std::endl;
    errors[10].display(); // Генерация исключения
  }
  catch (const std::range_error& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  return 0;
}

