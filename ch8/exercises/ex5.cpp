// Exercise 5 from Chapter 8 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>

using namespace std;

// Compute the maximum of 5 T's
template <typename T> T max5(T[]);

int main() {
  int ints[] = { 1, 2, 3, 4, 5 };
  double doubles[] = { -1.2, -3.4, -5.6, -7.8, -9.0 };

  cout << "max of ints is " << max5(ints) << endl;
  cout << "max of doubles is " << max5(doubles) << endl;
  return 0;
}

// Compute the maximum of 5 T's
template <typename T> T max5(T arr[]) {
  T max = arr[0];
  for (int i = 1; i < 5; i++) {
    T t = arr[i];
    if (t > max) max = t;
  }
  return max;
}
