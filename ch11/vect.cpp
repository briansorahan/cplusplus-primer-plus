// vector.cpp -- Vector class implementation

#include <cmath>
#include "vect.hpp"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::cerr;

namespace VECTOR {
  // compute degrees in one radian
  const double Rad_to_deg = 45.0 / atan(1.0);

  // private methods
  void Vector::setMag() {
    mag = sqrt(x*x + y*y);
  }

  void Vector::setAngle() {
    if (x == 0.0 && y == 0.0) {
      angle = 0.0;
    }
    else {
      angle = atan2(y, x);
    }
  }

  void Vector::setX() {
    x = mag * cos(angle);
  }

  void Vector::setY() {
    y = mag * sin(angle);
  }

  // public methods
  Vector::Vector() {
    x = y = mag = angle = 0.0;
  }

  Vector::Vector(double n1, double n2, Mode form) {
    mode = form;
    if (form == RECT) {
      x = n1;
      y = n2;
      setMag();
      setAngle();
    }
    else if (form == POL) {
      mag = n1;
      angle = n2 / Rad_to_deg;
      setX();
      setY();
    }
    else {
      cerr << "Incorrect 3rd argument to Vector -- "
	   << "vector set to 0\n";
      x = y = mag = angle = 0.0;
      mode = RECT;
    }
  }

  void Vector::reset(double n1, double n2, Mode form) {
    mode = form;
    if (form == RECT) {
      x = n1;
      y = n2;
      setMag();
      setAngle();
    }
    else if (form == POL) {
      mag = n1;
      angle = n2 / Rad_to_deg;
      setX();
      setY();
    }
    else {
      cerr << "Incorrect 3rd argument to Vector -- "
	   << "vector set to 0\n";
      x = y = mag = angle = 0.0;
      mode = RECT;
    }
  }

  Vector::~Vector() {}

  void Vector::polarMode() {
    mode = POL;
  }

  void Vector::rectMode() {
    mode = RECT;
  }

  Vector Vector::operator+(const Vector& v) const {
    return Vector(x + v.x, y + v.y);
  }

  Vector Vector::operator-(const Vector& v) const {
    return Vector(x - v.x, y - v.y);
  }

  Vector Vector::operator-() const {
    return Vector(-x, -y);
  }

  Vector Vector::operator*(double n) const {
    return Vector(n * x, n * y);
  }

  Vector operator*(double n, const Vector& v) {
    return v * n;
  }

  std::ostream& operator<<(std::ostream& os, const Vector& v) {
    if (v.mode == Vector::RECT) {
      os << "(x, y) = (" << v.x << ", " << v.y << ")";
    }
    else if (v.mode == Vector::POL) {
      os << "(m, a) = (" << v.mag << ", " << v.angle * Rad_to_deg << ")";
    }
    else {
      os << "Vector object mode is invalid";
    }

    return os;
  }
}
