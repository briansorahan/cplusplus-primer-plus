// Exercise 3 from Chapter 3 of C++ Primer

#include <iostream>

int main() {
  using namespace std;

  const int secs_per_min = 60;
  const int min_per_degree = 60;

  int degrees, minutes, seconds;
  cout << "Enter a latitude in degrees, minutes, and seconds:"
       << endl;
  cout << "Degrees: ";
  cin >> degrees;
  cout << "Minutes: ";
  cin >> minutes;
  cout << "Seconds: ";
  cin >> seconds;

  double result =
    degrees
    + ( double(minutes) /  double(min_per_degree) )
    + ( double(seconds) /  double(secs_per_min * min_per_degree) );

  cout << degrees << " degrees "
       << minutes << " minutes "
       << seconds << " seconds "
       << " = " << result << " degrees" << endl;

  return 0;
}
