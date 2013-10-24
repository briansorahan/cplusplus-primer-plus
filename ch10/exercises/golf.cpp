// golf.cpp -- Golf class implementation.
// Brian Sorahan

#include<iostream>
#include<cstring>
#include "golf.hpp"

Golf::Golf() {
}

Golf::Golf(const char* fn, int handicap) {
  Golf g;
  *this = g.setName(fn).setHandicap(handicap);
}

void Golf::setGolf(const char* fn, int hc) {
  *this = Golf(fn, hc);
}

// Get the fullname
const char* Golf::getName() const {
  return fullname;
}

// Set the name
Golf Golf::setName(const char* fn) {
  strcpy(this->fullname, fn);
  return *this;
}

// Get the current handicap
int Golf::getHandicap() const {
  return handicap;
}

// Set the handicap
Golf Golf::setHandicap(int hc) {
  this->handicap = hc;
  return *this;
}

void Golf::show() const {
  using std::cout;
  cout << fullname << ", handicap = " << handicap << "\n";
}
