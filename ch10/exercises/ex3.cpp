// Exercise 3 from Chapter 10 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include <cstring>
#include "golf.hpp"

int main() {
  using std::cout;
  using std::cin;

  const int MAX_GOLFERS = 100000;
  Golf golfers[MAX_GOLFERS];
  
  int i;
  for (i = 0; i < MAX_GOLFERS; i++) {
    char name[40];
    int handicap;

    cout << "Enter full name: ";
    cin.getline(name, 40);

    if (strlen(name) == 0) {
      break;
    }

    cout << "Enter handicap: ";
    (cin >> handicap).get();

    golfers[i].setGolf(name, handicap);
  }

  for (int j = 0; j < i; j++) {
    golfers[j].show();
  }

  return 0;
}
