// Exercise 5 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

int factorial(int);

int main() {
  using namespace std;

  int test = 6;
  cout << "factorial(" << test << ") = "
       << factorial(test) << endl;

  return 0;
}

int factorial(int n) {
  if (n <= 0) {
    return 0;
  }
  else if (n == 1) {
    return n;
  }
  else {
    return n * factorial(n - 1);
  }
}
