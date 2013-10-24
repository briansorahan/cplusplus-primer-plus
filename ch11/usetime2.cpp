// usetime2.cpp -- using the third draft of the Time class
// compile with mytime2.cpp

#include <iostream>
#include "mytime2.hpp"

int main() {
  using std::cout;
  using std::endl;

  Time weeding(4, 35);
  Time waxing(2, 47);
  Time total;
  Time diff;
  Time adjusted;

  cout << "weeding time = ";
  weeding.Show();

  cout << "waxing time = ";
  waxing.Show();

  cout << "total work time = ";
  total = weeding + waxing;
  total.Show();

  diff = weeding - waxing;
  cout << "weeding - waxing time = ";
  diff.Show();

  adjusted = total * 1.5;
  cout << "adjusted work time = ";
  adjusted.Show();

  return 0;
}
