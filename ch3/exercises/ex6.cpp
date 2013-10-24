// Exercise 6 from Chapter 3 of C++ Primer

#include <iostream>

int main() {
  using namespace std;

  double miles_driven, gas_consumed;
  cout << "How many miles have you driven? ";
  cin >> miles_driven;
  cout << "How many gallons of gas have you used? ";
  cin >> gas_consumed;

  cout << "Your current mpg is "
       << miles_driven / gas_consumed << endl;

  return 0;
}
