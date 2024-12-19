#include <iostream>
#include <vector>
#include <memory>
#include <random>

// Базовый класс Base
class Base {
public:
  virtual ~Base() = default;

  // Виртуальная функция для полиморфного поведения
  virtual void action() const {
    std::cout << "Action in Base\n";
  }
};

// Производный класс Derived
class Derived : public Base {
public:
  void action() const override {
    std::cout << "Action in Derived\n";
  }
};

// Функция add для добавления объектов в хранилище
void add(std::vector<std::shared_ptr<Base>>& storage, std::shared_ptr<Base> obj) {
  storage.push_back(obj);
}

int main() {
  std::vector<std::shared_ptr<Base>> storage;

  // Настройка генератора случайных чисел
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 1);

  // Создаем объекты случайным образом
  for (int i = 0; i < 10; ++i) {
    if (dist(gen) % 2 == 0) {
      add(storage, std::make_shared<Base>());
    } else {
      add(storage, std::make_shared<Derived>());
    }
  }

  // Полиморфный вызов функции action
  for (const auto& item : storage) {
    item->action();
  }

  // Память освобождается автоматически при завершении программы
  return 0;
}
