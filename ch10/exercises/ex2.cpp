// Exercise 2 from Chapter 10 of C++ Primer Plus
// Brian Sorahan

#include "person.hpp"

int main() {
  Person p1;
  Person p2("Howareya");
  Person p3("Buzzoff", "Heywouldya");

  p1.Show();
  p2.Show();
  p3.FormalShow();
  return 0;
}
