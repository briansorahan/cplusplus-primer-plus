// vect.h -- Vector class with <<, mode state

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR {
  class Vector {
  public:
    enum Mode { RECT, POL };
  private:
    double x;
    double y;
    Mode mode;
  public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void reset(double n1, double n2, Mode form = RECT);
    ~Vector();
    double getX() const { return x; }
    double getY() const { return y; }
    double getMag() const;
    double getAngle() const;
    void polarMode();
    void rectMode();
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator-() const;
    Vector operator*(double n) const;
    friend Vector operator*(double n, const Vector& v);
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
  };
}

#endif
