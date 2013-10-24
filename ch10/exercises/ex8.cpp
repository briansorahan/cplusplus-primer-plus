// Exercise 8 from Chapter 10 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include "list.hpp"

void printPlatypus(platypus p);

int main() {
  using std::cout;

  platypus ry = {
    "Ry Wright",
    16
  };

  platypus bri = {
    "Bri Bri",
    15
  };

  List l;
  
  if(l.add(ry)) {
    cout << "Added " << ry.name << ".\n";
  }
  else {
    cout << "Could not add " << ry.name << ".\n";
  }

  if(l.add(bri)) {
    cout << "Added " << bri.name << ".\n";
  }
  else {
    cout << "Could not add " << bri.name << ".\n";
  }

  cout << "Here is the list:\n";
  l.visit(&printPlatypus);

  return 0;
}

void printPlatypus(platypus p) {
  using std::cout;
  cout << "Platypus: " << p.name << ", " << p.age << "\n";
}
