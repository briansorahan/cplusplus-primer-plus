// move.hpp -- move an object around in 2D space

#ifndef MOVE_H_
#define MOVE_H_

class Move {
private:
  double x;
  double y;
public:
  Move(double a = 0, double b = 0);
  int toString(char*) const;
  // this function adds x and y of m to x and y
  // of invoking object and returns a newly initialized
  // Move object with the new coordinates
  Move add(const Move& m);
  void reset(double a = 0, double b = 0);
};

#endif
