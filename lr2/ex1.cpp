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
    cin.ignore(); // Очистить буфер ввода
  }
  virtual void putData() const {
    cout << "Title: " << title << endl;
    cout << "Price: $" << price << endl;
  }
};

class Book : public Publication {
private:
  int pageCount;
public:
  void getData() override {
    Publication::getData(); // Вызов метода базового класса
    cout << "Enter number of pages: ";
    cin >> pageCount;
    cin.ignore(); // Очистить буфер ввода
  }
  void putData() const override {
    Publication::putData(); // Вызов метода базового класса
    cout << "Pages: " << pageCount << endl;
  }
};

class Type : public Publication {
private:
  float playTime; // Время записи в минутах
public:
  void getData() override {
    Publication::getData(); // Вызов метода базового класса
    cout << "Enter play time (in minutes): ";
    cin >> playTime;
    cin.ignore(); // Очистить буфер ввода
  }
  void putData() const override {
    Publication::putData(); // Вызов метода базового класса
    cout << "Play time: " << playTime << " minutes" << endl;
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
