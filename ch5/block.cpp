// block.cpp -- use a block statement

#include <iostream>

int main() {
  using namespace std;

  cout << "The Amazing Accounto will sum and average "
       << "five numbers for you." << endl;
  cout << "Please enter five values:" << endl;

  double number;
  double sum = 0.0;
  for (int i = 1; i <= 5; i++) {
    cout << "Value " << i << ": ";
    cin >> number;
    sum += number;
  }

  cout << "Five exquisite choices indeed: "
       << "They sum to " << sum << endl
       << "and average to " << sum / 5.0 << endl
       << "The Amazing Accounto bids you adieu!" << endl;

  return 0;
}
