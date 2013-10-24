// Exercise 1 from Chapter 11 of C++ Primer Plus
// Writing a random-walk to a file.
// Brian Sorahan

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vect.hpp"

static const int E_FILE_NOT_OPEN = 6;

int main() {
  using namespace std;
  using VECTOR::Vector;

  ofstream outFile;
  outFile.open("randwalk.out");

  if (! outFile.is_open()) {
    exit(E_FILE_NOT_OPEN);
  }

  srand(time(0)); // seed random-number generator
  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  double target;
  double dstep;
  cout << "Enter the target distance (q to quit): ";

  while (cin >> target) {
    cout << "Enter step length: ";
    if (!(cin >> dstep)) break;

    outFile << "Target Distance: " << target << ", "
	    << "Step Size: " << dstep << endl;

    while (result.getMag() < target) {
      outFile << steps << ": " << result << endl;
      direction = rand() % 360;
      step.reset(dstep, direction, Vector::POL);
      result = result + step;
      steps++;
    }

    outFile << "After " << steps << " steps, the subject "
	    << "has the following location:\n"
	    << result << endl;

    result.polarMode();
    outFile << " or\n" << result << endl;
    outFile << "Average outward distance per step = "
	    << result.getMag() / steps << endl;

    steps = 0;
    result.reset(0.0, 0.0);
    cout << "Enter the target distance (q to quit): ";
  }

  cout << "Bye!\n";
  cin.clear();
  while (cin.get() != '\n') continue;

  outFile.close();
  return 0;
}
