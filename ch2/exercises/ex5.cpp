// Exercise 5 from Chapter 2 of C++ Primer
//
#include <iostream>

int c_to_f(int c);

int main() {
  using namespace std;

  int celsius;
  cout << "Please enter a Celsius value: ";
  cin >> celsius;

  int fahrenheit = c_to_f(celsius);
  cout << celsius    << " degrees Celsius is ";
  cout << fahrenheit << " degrees Fahrenheit.";
  cout << endl;

  return 0;
}

int c_to_f(int c) {
  return ((9.0 / 5.0) * c) + 32;
}
