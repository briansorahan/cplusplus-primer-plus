// complex0.cpp -- complex number class implementation

#include <iostream>
#include "complex0.hpp"

// constructor
complex::complex(double a, double b) {
  real = a; imag = b;
}

// destructor
complex::~complex() {}

complex complex::operator+(const complex& c) const {
  complex sum;
  sum.real = real + c.real;
  sum.imag = imag + c.imag;
  return sum;
}

complex complex::operator-(const complex& c) const {
  complex diff;
  diff.real = real - c.real;
  diff.imag = imag - c.imag;
  return diff;
}

complex operator~(complex& c) {
  return complex(c.real, -1.0 * c.imag);
}

complex complex::operator*(const complex& c) const {
  complex prod;
  prod.real = (real * c.real) - (imag * c.imag);
  prod.imag = (real * c.imag) + (imag + c.real);
  return prod;
}

complex operator*(double n, const complex& c) {
  return c * complex(n, 0);
}

std::ostream& operator<<(std::ostream& os, const complex& c) {
  os << "(" << c.real << ", " << c.imag << ")";
  return os;
}

std::istream& operator>>(std::istream& is, complex& c) {
  std::cout << "real: ";
  is >> c.real;
  if (! is) return is;

  std::cout << "imag: ";
  return is >> c.imag;
}
