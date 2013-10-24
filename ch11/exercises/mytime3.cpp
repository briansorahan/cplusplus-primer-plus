// mytime3.cpp -- Time class implementation

#include <iostream>
#include "mytime3.hpp"

Time::Time() {
  hours = minutes = 0;
}

Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}

void Time::AddMin(int m) {
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h) {
  hours += h;
}

void Time::Reset(int h, int m) {
  hours = h;
  minutes = m;
}

Time operator+(const Time& t1, const Time& t2) {
  Time sum;
  sum.minutes = t1.minutes + t2.minutes;
  sum.hours = t1.hours + t2.hours + sum.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

Time operator-(const Time& t1, const Time& t2) {
  Time difference;
  int tot1, tot2;
  tot1 = t1.minutes + 60 * t1.hours;
  tot2 = t2.minutes + 60 * t2.hours;
  difference.minutes = (tot2 - tot1) % 60;
  difference.hours = (tot2 - tot1) / 60;
  return difference;
}

Time operator*(const Time& t, double n) {
  Time product;
  long totalMinutes = (t.hours * n * 60) + (t.minutes * n);
  product.hours = totalMinutes / 60;
  product.minutes = totalMinutes % 60;
  return product;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
  os << t.hours << " hrs " << t.minutes << " min";
  return os;
}
