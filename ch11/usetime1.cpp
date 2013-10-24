// usetime1.cpp -- using the first draft of the Time class
// compile usetime1.cpp and mytime1.cpp together

#include <iostream>
#include "mytime1.hpp"

int main() {
  using std::cout;
  using std::endl;

  Time planning;
  Time coding(2, 40);
  Time fixing(5, 55);
  Time total;

  cout << "planning time = ";
  planning.Show();

  cout << "coding time = ";
  coding.Show();

  cout << "fixing time = ";
  fixing.Show();

  total = coding + fixing;
  cout << "coding + fixing = ";
  total.Show();

  Time morefixing(3, 28);
  cout << "more fixing time = ";
  morefixing.Show();
  total = morefixing.operator+(total);
  cout << "morefixing.operator+(total) = ";
  total.Show();

  return 0;
}
