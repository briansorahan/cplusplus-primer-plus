// Exercise 1 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

// Gets a pair of numbers from user input
// and returns the harmonic mean.
// Terminates if one of the numbers is 0.
void getPair();
double harmonicMean(double, double);

int main() {
  while (true) {
    getPair();
  }
}

void getPair() {
  double x, y;
  std::cout << "Enter a pair of numbers:\n";
  std::cin >> x >> y;

  if (x == 0 || y == 0) {
    std::cout << "Goodbye!" << std::endl;
    exit(1);
  }
  else {
    std::cout << "Harmonic mean = "
	      << harmonicMean(x, y)
	      << std::endl;
  }
}

double harmonicMean(double x, double y) {
  if (x + y == 0) {
    exit(1);
  }
  else {
    return (2.0 * x * y) / (x + y);
  }
}
