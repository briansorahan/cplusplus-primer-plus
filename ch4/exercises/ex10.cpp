// Exercise 5 from Chapter 4 of C++ Primer

#include <iostream>
#include <array>

int main() {
  using namespace std;

  array<double, 3> times;
  cout << "Enter three times for the 40-yd dash:" << endl;
  cout << " ---> ";
  cin >> times[0];
  cout << " ---> ";
  cin >> times[1];
  cout << " ---> ";
  cin >> times[2];

  double average = (times[0] + times[1] + times[2]) / 3.0;
  cout << "The times were: "
       << times[0] << ", "
       << times[1] << ", "
       << times[2] << endl;
  cout << "The average time is: " << average << endl;

  return 0;
}
