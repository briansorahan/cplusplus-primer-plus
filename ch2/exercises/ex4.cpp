// Exercise 4 from Chapter 2 of C++ Primer
//
#include <iostream>

int yrs_to_months(int yrs);

int main() {
  using namespace std;

  int years;
  cout << "Please enter your age in years: ";
  cin >> years;

  int months = yrs_to_months(years);
  cout << "Your age in months = " << months << endl;

  return 0;
}

int yrs_to_months(int yrs) {
  return yrs * 12;
}
