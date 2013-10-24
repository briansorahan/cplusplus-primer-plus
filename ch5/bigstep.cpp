// bigstep.cpp -- count as directed

#include <iostream>

int main() {
  using std::cout;
  using std::cin;
  using std::endl;

  cout << "Enter an integer: ";
  int step;
  cin >> step;
  cout << "Counting by " << step << "'s ..." << endl;

  for (int i = 0; i < 100; i += step) {
    cout << i << endl;
  }

  return 0;
}
