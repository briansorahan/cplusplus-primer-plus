// cow.cpp -- Cow implementation

#include <iostream>
#include <cstring>
#include "cow.hpp"

Cow::Cow() {
  name[0] = '\0';
  hobby = new char[40];
  weight = 0;
}

Cow::Cow(const char* nm, const char* hob, double wt) {
  hobby = new char[40];
  strcpy(name, nm);
  strcpy(hobby, hob);
  weight = wt;
}

Cow::Cow(const Cow& c) {
  hobby = new char[40];
  strcpy(name, c.name);
  strcpy(hobby, c.hobby);
  weight = c.weight;
}

Cow::~Cow() {
  delete [] hobby;
}

Cow& Cow::operator=(const Cow& c) {
  if (this == &c) return *this;
  strcpy(name, c.name);
  strcpy(hobby, c.hobby);
  weight = c.weight;
  return *this;
}

void Cow::ShowCow() const { // display cow's data on stdout
  using std::cout;
  using std::endl;
  cout << "-------- Cow --------" << endl
       << "name:   " << name << endl
       << "hobby:  " << hobby << endl
       << "weight: " << weight << endl;
}
