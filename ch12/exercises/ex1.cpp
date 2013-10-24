// Exercise 1 from Chapter 12 of C++ Primer Plus
// Brian Sorahan
// Note: compile with cow.cpp

#include <iostream>
#include "cow.hpp"

int main() {
  Cow* bessie = new Cow("bessie", "chewing cud", 400);
  Cow moo("moo", "mooing", 390);
  Cow bessie2(*bessie);
  Cow moo2;
  moo2 = moo;

  bessie->ShowCow();
  bessie2.ShowCow();
  moo.ShowCow();
  moo2.ShowCow();

  delete bessie;
  return 0;
}
