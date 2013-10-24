// Exercise 6 from Chapter 10 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include "move.hpp"

int main() {
  using std::cout;

  Move m1(1.0, 2.0);
  Move m2(2, 3);
  char result[80];
  
  m1.toString(result);
  cout << "m1 = " << result << "\n";
  m2.toString(result);
  cout << "m2 = " << result << "\n";
  m2.add(m1).toString(result);
  cout << "m1 + m2 = " << result << "\n";
  m1.toString(result);
  cout << "m1 = " << result << "\n";
  m2.toString(result);
  cout << "m2 = " << result << "\n";

  return 0;
}
