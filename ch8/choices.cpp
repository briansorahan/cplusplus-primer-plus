// choices.cpp -- choosing a template

#include<iostream>

// #1
template <class T> T lesser(T a, T b) {
  return a < b ? a : b;
}

// #2
int lesser(int a, int b) {
  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;
  return a < b ? a : b;
}

int main() {
  using namespace std;

  int m = 20, n = -30;
  double x = 15.5, y = 25.9;

  cout << lesser(m, n) << endl; // uses #2
  cout << lesser(x, y) << endl; // uses #1 with double
  cout << lesser<>(m, n) << endl; // uses #1 with int
  cout << lesser<int>(x, y) << endl; // uses #1 with int

  return 0;
}
