// move.cpp -- Implementation for the Move class

#include <string>
#include <stdio.h>
#include "move.hpp"

Move::Move(double a, double b) {
  x = a; y = b;
}

// Copy the string representation of this Move object into
// str and return the number of characters copied.
int Move::toString(char* str) const {
  return sprintf(str, "(%f, %f)", this->x, this->y);
}

// this function adds x and y of m to x and y
// of invoking object and returns a newly initialized
// Move object with the new coordinates
Move Move::add(const Move& m) {
  return Move(this->x + m.x, this->y + m.y);
}

void Move::reset(double a, double b) {
  x = a; b = y;
}
