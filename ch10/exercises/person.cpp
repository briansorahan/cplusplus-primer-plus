// person.cpp -- Person implementation.

#include <iostream>
#include <cstring>
#include "person.hpp"

Person::Person(const std::string& ln, const char* fn) {
  lname = ln;
  strcpy(fname, fn);
}

void Person::Show() const {
  std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow() const {
  std::cout << lname << ", " << fname << std::endl;
}
