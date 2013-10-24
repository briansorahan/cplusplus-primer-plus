// Exercise 3 from Chapter 11 of C++ Primer Plus
// Writing a random-walk to a file.
// Brian Sorahan

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.hpp"

static const int E_NUMBER_FORMAT = 7;

int main() {
  using namespace std;
  using VECTOR::Vector;

  srand(time(0)); // seed random-number generator
  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  unsigned long highest = 0;
  unsigned long lowest = 0;
  unsigned long total = 0;
  unsigned int ntrials = 1;
  double target;
  double dstep;
  cout << "Enter the number of trials to run: ";
  if (! (cin >> ntrials)) exit(E_NUMBER_FORMAT);

  cout << "Enter the target distance (q to quit): ";
  if (! (cin >> target)) exit(E_NUMBER_FORMAT);

  cout << "Enter step length: ";
  if (! (cin >> dstep)) exit(E_NUMBER_FORMAT);

  for (int i = 0; i < ntrials; i++) {
    while (result.getMag() < target) {
      direction = rand() % 360;
      step.reset(dstep, direction, Vector::POL);
      result = result + step;
      steps++;
    }
    
    if (steps > highest) highest = steps;
    if (lowest == 0 || steps < lowest) lowest = steps;
    total += steps;
    
    steps = 0;
    result.reset(0.0, 0.0);
  }

  cout << "The lowest number of steps was " << lowest << endl;
  cout << "The highest number of steps was " << highest << endl;
  cout << "The average number of steps was " << total / ntrials << endl;

  cin.clear();
  while (cin.get() != '\n') continue;

  return 0;
}
