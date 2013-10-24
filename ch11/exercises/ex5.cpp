// Exercise 5 from Chapter 11 of C++ Primer Plus
// Brian Sorahan
//
// note:
// compile with stonewt.cpp

#include <iostream>
#include "stonewt.hpp"

int main() {
  using std::cout;
  using std::endl;
  using stonewt::Stonewt;

  Stonewt wt1(90.0);
  Stonewt wt2(85.0);
  Stonewt wt3(7, 17.0, stonewt::INT_LBS);
  Stonewt wt4(3, 0.0, stonewt::STONE);
  Stonewt wt5(2);
  Stonewt sum, diff, prod;

  cout << "wt1 = " << wt1 << endl;
  cout << "wt2 = " << wt2 << endl;
  cout << "wt3 = " << wt3 << endl;
  cout << "wt4 = " << wt4 << endl;
  cout << "wt5 = " << wt5 << endl;

  sum = wt1 + wt2;
  sum.setState(stonewt::STONE);
  cout << "wt1 + wt2 = " << sum << endl;

  diff = wt3 - wt2;
  diff.setState(stonewt::FLOAT_LBS);
  cout << "wt3 - wt2 = " << diff << endl;

  prod = wt4 * wt5;
  cout << "wt4 * wt5 = " << prod << endl;

  return 0;
}
