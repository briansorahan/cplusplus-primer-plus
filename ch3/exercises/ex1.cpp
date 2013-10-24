// Exercise 1 from Chapter 3 of C++ Primer

#include <iostream>

int main() {
  using namespace std;

  const int inches_per_foot = 12;
  int height;
  cout << "Please enter your height in inches:______\b\b\b\b\b";
  cin >> height;

  int feet = height / inches_per_foot;
  int inches = height % inches_per_foot;

  cout << "That is equivalent to "
       << feet << "'" << inches << '"' << endl;

  return 0;
}
