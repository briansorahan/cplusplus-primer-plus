// Exercise 6 from Chapter 11 of C++ Primer Plus
// Brian Sorahan
//
// note:
// compile with stonewt1.cpp

#include <iostream>
#include "stonewt1.hpp"

int main() {
  using std::cout;
  using std::endl;
  using stonewt::Stonewt;

  Stonewt wt1(90.0);
  Stonewt wt2(85.0);
  Stonewt wt3(7, 17.0, stonewt::INT_LBS);
  Stonewt wt4(3, 0.0, stonewt::STONE);
  Stonewt wt5(2);
  Stonewt wt6(84);
  Stonewt sum, diff, prod;
  bool result;

  cout << "wt1 = " << wt1 << endl;
  cout << "wt2 = " << wt2 << endl;
  cout << "wt3 = " << wt3 << endl;
  cout << "wt4 = " << wt4 << endl;
  cout << "wt5 = " << wt5 << endl;
  cout << "wt6 = " << wt6 << endl;

  sum = wt1 + wt2;
  sum.setState(stonewt::STONE);
  cout << "wt1 + wt2 = " << sum << endl;

  diff = wt3 - wt2;
  diff.setState(stonewt::FLOAT_LBS);
  cout << "wt3 - wt2 = " << diff << endl;

  prod = wt4 * wt5;
  cout << "wt4 * wt5 = " << prod << endl;

  result = wt2 < wt1;
  if (result)
    cout << "wt2 < wt1 is true" << endl;
  else
    cout << "wt2 < wt1 is false" << endl;

  result = wt1 <= wt2;
  if (result)
    cout << "wt1 <= wt2 is true" << endl;
  else
    cout << "wt1 <= wt2 is false" << endl;

  result = wt3 > wt4;
  if (result)
    cout << "wt3 > wt4 is true" << endl;
  else
    cout << "wt3 > wt4 is false" << endl;

  result = wt4 >= wt5;
  if (result)
    cout << "wt4 >= wt5 is true" << endl;
  else
    cout << "wt4 >= wt5 is false" << endl;

  result = wt4 * wt5 == wt6;
  if (result)
    cout << "wt4 * wt5 == wt6 is true" << endl;
  else
    cout << "wt4 * wt5 == wt6 is false" << endl;

  result = wt5 != wt6;
  if (result)
    cout << "wt5 != wt6 is true" << endl;
  else
    cout << "wt5 != wt6 is false" << endl;

  return 0;
}
