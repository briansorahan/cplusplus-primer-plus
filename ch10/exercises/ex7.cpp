// Exercise 7 from Chapter 10 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include "plorg.hpp"

int main() {
  Plorg plorgie("plorgie", 34);
  Plorg bess("bess", 56);

  plorgie.show();
  bess.show();

  std::cout << "Bess is becoming very content...\n";
  bess.setCI(99);

  plorgie.show();
  bess.show();

  return 0;
}
