// Exercise 10 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

// calculate
// Args:
// 1) double
// 2) double
// 3) pointer to a function that takes two double args
//    and returns a double
// Returns:
// The double calculated by the function provided as a third argument
double calculate(double, double, double (*)(double, double));

// We use this function to test.
double add(double, double);

int main() {
  using namespace std;
  
  cout << "add(3.75, 1.25) = " << calculate(3.75, 1.25, add) << endl;
  
  return 0;
}

double calculate(double x, double y, double (*f)(double p1, double p2)) {
  return f(x, y);
} 

double add(double x, double y) {
  return x + y;
}
