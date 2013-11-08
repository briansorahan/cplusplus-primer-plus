// stonewt1.hpp -- definition for the Stonewt class

#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

namespace stonewt {
  enum State { STONE, INT_LBS, FLOAT_LBS };

  class Stonewt {
  private:
    enum { Lbs_per_stn = 14 };
    State state;
    // Note:
    // pounds == (stone * Lbs_per_stn) + pds_left
    int stone; // Stones component of weight
    double pds_left; // Pounds component of weight
    double pounds; // Total weight in lbs
    // Ensure that the private variables all add up.
    void normalize();

  public:
    Stonewt(double lbs, State state = FLOAT_LBS);
    Stonewt(int stn, double lbs, State state = FLOAT_LBS);
    Stonewt(State state = FLOAT_LBS);
    ~Stonewt();
    void setState(State);
    Stonewt operator+(const Stonewt& st) const;
    Stonewt operator-(const Stonewt& st) const;
    Stonewt operator*(const Stonewt& st) const;
    bool operator<(const Stonewt& st) const;
    bool operator<=(const Stonewt& st) const;
    bool operator>(const Stonewt& st) const;
    bool operator>=(const Stonewt& st) const;
    bool operator==(const Stonewt& st) const;
    bool operator!=(const Stonewt& st) const;
    friend std::ostream& operator<<(std::ostream& os, const Stonewt& wt);
  };
}

#endif
