// Exercise 5 from Chapter 6 of C++ Primer Plus
// Brian Sorahan
// 
// Note:
// I didn't think the instructions for this problem
// were very clear.

#include<iostream>

// get tax owed in tvarps
double getTax(double income);

int main() {
  using std::cin;
  using std::cout;

  cout << "Please enter incomes:\n";

  double income;
  while(cin >> income) {
    if (income < 0) {
      continue;
    }

    cout << "... tax = " << getTax(income) << "\n";
  }

  return 0;
}

double getTax(double income) {
  using std::cout;

  // Variables that define the tax brackets
  const int brackets[4] = {5000, 10000, 20000};
  const double rates[4] = {0.0, 0.1, 0.15};

  // Anything you make over this amount is subject to
  // the given rate
  const double max = 35000;
  const double maxRate = 0.2;

  double tax;
  int numBrackets = (sizeof brackets / sizeof(int));
  for (int i = 0; i < numBrackets; i++) {
    if (income >= brackets[i]) {
      tax += brackets[i] * rates[i];
    }
  }

  if (income > max) {
    tax += (income - max) * maxRate;
  }

  return tax;
}
