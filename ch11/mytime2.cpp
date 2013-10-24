// mytime2.cpp -- Time class implementation with operator overloading

#include <iostream>
#include "mytime2.hpp"

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

Time Time::operator+(const Time& t) const {
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours + sum.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

Time Time::operator-(const Time& t) const {
  Time difference;
  int tot1, tot2;
  tot1 = t.minutes + 60 * t.hours;
  tot2 = minutes + 60 * hours;
  difference.minutes = (tot2 - tot1) % 60;
  difference.hours = (tot2 - tot1) / 60;
  return difference;
}

Time Time::operator*(double n) const {
  Time product;
  long totalMinutes = (hours * n * 60) + (minutes * n);
  product.hours = totalMinutes / 60;
  product.minutes = totalMinutes % 60;
  return product;
}

void Time::Show() const {
  std::cout << hours << ":" << minutes << ":000\n";
}
