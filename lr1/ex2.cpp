#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
  string title;
  float price;
public:
  virtual void getData() {
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter price: ";
    cin >> price;
    cin.ignore();  // Очистить буфер ввода
  }

  virtual void putData() const {
    cout << "Title: " << title << endl;
    cout << "Price: $" << price << endl;
  }
};

class Sales {
protected:
  float sales[3];  // Массив для стоимости проданных книг за 3 месяца
public:
  void getSalesData() {
    cout << "Enter sales data for the last 3 months:\n";
    for (int i = 0; i < 3; i++) {
      cout << "Month " << (i + 1) << ": $";
      cin >> sales[i];
    }
    cin.ignore();  // Очистить буфер ввода
  }

  void putSalesData() const {
    cout << "Sales data for the last 3 months:\n";
    for (int i = 0; i < 3; i++) {
      cout << "Month " << (i + 1) << ": $" << sales[i] << endl;
    }
  }
};

class Book : public Publication, public Sales {
private:
  int pageCount;
public:
  void getData() override {
    Publication::getData();  // Вызов метода базового класса
    cout << "Enter number of pages: ";
    cin >> pageCount;
    cin.ignore();  // Очистить буфер ввода
    getSalesData();  // Ввод данных о продажах
  }

  void putData() const override {
    Publication::putData();  // Вызов метода базового класса
    cout << "Pages: " << pageCount << endl;
    putSalesData();  // Вывод данных о продажах
  }
};

class Type : public Publication, public Sales {
private:
  float playTime;  // Время записи в минутах
public:
  void getData() override {
    Publication::getData();  // Вызов метода базового класса
    cout << "Enter play time (in minutes): ";
    cin >> playTime;
    cin.ignore();  // Очистить буфер ввода
    getSalesData();  // Ввод данных о продажах
  }

  void putData() const override {
    Publication::putData();  // Вызов метода базового класса
    cout << "Play time: " << playTime << " minutes" << endl;
    putSalesData();  // Вывод данных о продажах
  }
};

int main() {
  Book book;
  Type audio;

  cout << "Enter data for a book:\n";
  book.getData();
  cout << "\nBook data:\n";
  book.putData();

  cout << "\nEnter data for an audio recording:\n";
  audio.getData();
  cout << "\nAudio recording data:\n";
  audio.putData();

  return 0;
}

