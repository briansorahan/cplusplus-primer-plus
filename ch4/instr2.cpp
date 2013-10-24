// instr2.cpp -- reading more than one word with getline

#include <iostream>

int main() {
  using namespace std;

  const int arr_size = 80;

  char name[arr_size];
  char dessert[arr_size];

  cout << "Enter your name:" << endl;
  cin.getline(name, arr_size);

  cout << "Enter your favorite dessert:" << endl;
  cin.getline(dessert, arr_size);

  cout << "I have some delicious " << dessert
       << " for you, " << name << "." << endl;

  return 0;
}
