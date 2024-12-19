#include <iostream>
#include <vector>
#include <memory>

// Базовый класс Detail
class Detail {
protected:
  // Защищенный конструктор, чтобы запретить прямое создание объектов
  Detail() {
    std::cout << "Detail created\n";
  }

public:
  // Виртуальный деструктор для корректного удаления производных объектов
  virtual ~Detail() {
    std::cout << "Detail destroyed\n";
  }

  // Чисто виртуальная функция для полиморфного поведения
  virtual void show() const = 0;
};

// Производный класс Assembly
class Assembly : public Detail {
protected:
  // Защищенный конструктор
  Assembly() {
    std::cout << "Assembly created\n";
  }

public:
  ~Assembly() override {
    std::cout << "Assembly destroyed\n";
  }

  // Переопределение виртуальной функции show
  void show() const override {
    std::cout << "This is an Assembly\n";
  }

  // Фабричная функция для создания объектов Assembly
  static std::shared_ptr<Assembly> create() {
    return std::shared_ptr<Assembly>(new Assembly());
  }
};

// Шаблонная функция для создания объектов и добавления в хранилище
template<typename T>
std::shared_ptr<T> createObject(std::vector<std::shared_ptr<Detail>>& storage) {
  static_assert(std::is_base_of<Detail, T>::value, "T must inherit from Detail");
  auto obj = T::create(); // Используем фабричную функцию для создания объекта
  storage.push_back(obj);
  return obj;
}

int main() {
  std::vector<std::shared_ptr<Detail>> storage;

  // Создание объектов через дружественную функцию
  createObject<Assembly>(storage);

  // Полиморфный вызов функции show
  for (const auto& item : storage) {
    item->show();
  }

  // Память освобождается автоматически при завершении программы
  return 0;
}
