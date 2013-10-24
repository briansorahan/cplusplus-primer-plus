// instr3.cpp -- reading more than one word with get().get()

#include <iostream>

int main() {
  using namespace std;

  const int arr_size = 80;

  char name[arr_size];
  char dessert[arr_size];

  cout << "Enter your name:" << endl;
  cin.get(name, arr_size).get();

  cout << "Enter your favorite dessert:" << endl;
  cin.get(dessert, arr_size).get();

  cout << "I have some delicious " << dessert
       << " for you, " << name << "." << endl;

  return 0;
}
