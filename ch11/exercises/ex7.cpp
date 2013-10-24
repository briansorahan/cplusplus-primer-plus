// Exercise 7 from Chapter 11 of C++ Primer Plus
// Brian Sorahan
//
// note:
// compile with complex.cpp

#include <iostream>
#include "complex0.hpp"

using namespace std;

int main() {
  complex a(3.0, 4.0);
  complex c;

  cout << "Enter a complex number (q to quit):\n";

  while (cin >> c) {
    cout << "c = " << c << '\n';
    cout << "complex conjugate = " << ~c << '\n';
    cout << "a = " << a << '\n';
    cout << "a + c = " << a + c << '\n';
    cout << "a - c = " << a - c << '\n';
    cout << "a * c = " << a * c << '\n';
    cout << "2 * c = " << 2 * c << '\n';
    cout << "Enter a complex number (q to quit):\n";
  }

  cout << "Done!\n";

  return 0;
}
