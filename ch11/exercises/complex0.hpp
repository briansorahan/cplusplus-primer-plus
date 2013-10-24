// complex0.hpp -- complex number class def

#include <iostream>

class complex {
private:
  double real;
  double imag;
public:
  complex(double a = 0.0, double b = 0.0);
  ~complex();
  complex operator+(const complex& c) const;
  complex operator-(const complex& c) const;
  complex operator*(const complex& c) const;
  friend complex operator~(complex& c);
  friend complex operator*(double n, const complex& c);
  friend std::ostream& operator<<(std::ostream& os, const complex& c);
  friend std::istream& operator>>(std::istream& is, complex& c);
};
