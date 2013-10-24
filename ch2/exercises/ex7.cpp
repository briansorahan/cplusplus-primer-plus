// Exercise 7 from Chapter 2 of C++ Primer
//
#include <iostream>

void print_time(int hrs, int min);

int main() {
  using namespace std;

  int hrs;
  cout << "Enter the number of hours: ";
  cin >> hrs;

  int min;
  cout << "Enter the number of minutes ";
  cin >> min;

  print_time(hrs, min);

  return 0;
}

void print_time(int hrs, int min) {
  using namespace std;
  cout << "Time: " << hrs << ":" << min << endl;
}
