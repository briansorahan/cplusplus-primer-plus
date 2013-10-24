// Exercise 6 from Chapter 3 of C++ Primer

#include <iostream>

double mpg_to_lp100k(double mpg);

int main() {
  using namespace std;

  double mpg, lp100k;
  cout << "Please enter your mpg: ";
  cin >> mpg;
  cout << "Your fuel consumption in liters/100km = "
       << mpg_to_lp100k(mpg) << endl;

  return 0;
}

double mpg_to_lp100k(double mpg) {
  return 1.0 / (mpg / 62.14 / 3.875);
}
