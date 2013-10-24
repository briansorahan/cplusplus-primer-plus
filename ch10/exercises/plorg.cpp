// Plorg implementation
// Brian Sorahan

#include <iostream>
#include <cstring>
#include "plorg.hpp"

// default constructor
Plorg::Plorg() {
  strcpy(name, "Plorga");
  ci = 50;
}

Plorg::Plorg(const char* name, int ci) {
  strcpy(this->name, name);
  this->ci = ci;
}

void Plorg::setCI(int ci) {
  this->ci = ci;
}

void Plorg::show() const {
  using std::cout;
  cout << "Plorg:\n";
  cout << "    name: " << name << "\n";
  cout << "    ci:   " << ci << "\n";
}
