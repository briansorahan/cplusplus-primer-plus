// randwalk.cpp -- using the Vector class
// compile with vect.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.hpp"


int main() {
  using namespace std;
  using VECTOR::Vector;
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

    while (result.getMag() < target) {
      direction = rand() % 360;
      step.reset(dstep, direction, Vector::POL);
      result = result + step;
      steps++;
    }

    cout << "After " << steps << " steps, the subject "
	 << "has the following location:\n"
	 << result << endl;

    result.polarMode();
    cout << " or\n" << result << endl;
    cout << "Average outward distance per step = "
	 << result.getMag() / steps << endl;

    steps = 0;
    result.reset(0.0, 0.0);
    cout << "Enter the target distance (q to quit): ";
  }

  cout << "Bye!\n";
  cin.clear();
  while (cin.get() != '\n') continue;

  return 0;
}
