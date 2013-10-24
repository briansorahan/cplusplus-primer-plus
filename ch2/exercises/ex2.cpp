// Exercise 2 from Chapter 2 of C++ Primer
//
#include <iostream>

int furlongs_to_yds(int furlongs);

int main() {
  using namespace std;
  cout << "### Furlongs to Yards converter ###" << endl;

  int furlongs;
  cout << "Enter distance in furlongs: ";
  cin >> furlongs;

  int yards = furlongs_to_yds(furlongs);
  cout << "Equivalent distance in yards = " << yards << endl;

  return 0;
}

int furlongs_to_yds(int furlongs) {
  return furlongs * 220;
}
