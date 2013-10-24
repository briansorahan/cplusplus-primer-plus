// Exercise 6 from Chapter 2 of C++ Primer
//
#include <iostream>

int ltyrs_to_au(double ltyrs);

int main() {
  using namespace std;

  double light_years;
  cout << "Enter the number of light years: ";
  cin >> light_years;

  int au = ltyrs_to_au(light_years);
  cout << light_years    << " light years = ";
  cout << au << " astronomical units.";
  cout << endl;

  return 0;
}

int ltyrs_to_au(double ltyrs) {
  return ltyrs * 63240;
}
