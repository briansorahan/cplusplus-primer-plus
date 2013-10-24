// express.cpp -- values of expressions

#include <iostream>

int main() {
  using namespace std;

  int x;
  cout << "The expression x = 100 has the value " 
       << (x = 100) << endl;
  cout << "Now x = " << x << endl;
  cout << "The expression x = 3 has the value "
       << (x = 3) << endl;
  cout << "The expression x < 3 has the value "
       << (x < 3) << endl;
  cout << "The expression x > 3 has the value "
       << (x > 3) << endl;

  return 0;
}
