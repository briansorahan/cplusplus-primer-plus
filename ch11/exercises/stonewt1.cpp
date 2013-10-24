// stonewt1.cpp -- Stonewt implementation with relational operators

#include <iostream>
#include "stonewt1.hpp"

using std::cout;

namespace stonewt {
  Stonewt::Stonewt(double lbs, State state) {
    this->state = state;
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
  }

  Stonewt::Stonewt(int stn, double lbs, State state) {
    this->state = state;
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
  }

  Stonewt::Stonewt(State state) {
    this->state = state;
    stone = pounds = pds_left = 0;
  }

  // destructor
  Stonewt::~Stonewt() {
  }

  void Stonewt::setState(State state) {
    this->state = state;
  }

  Stonewt Stonewt::operator+(const Stonewt& st) const {
    Stonewt sum(pounds + st.pounds);
    return sum;
  }

  Stonewt Stonewt::operator-(const Stonewt& st) const {
    Stonewt diff(pounds - st.pounds);
    return diff;
  }

  Stonewt Stonewt::operator*(const Stonewt& st) const {
    Stonewt prod(pounds * st.pounds);
    return prod;
  }

  bool Stonewt::operator<(const Stonewt& st) const {
    return pounds < st.pounds;
  }

  bool Stonewt::operator<=(const Stonewt& st) const {
    return pounds <= st.pounds;
  }

  bool Stonewt::operator>(const Stonewt& st) const {
    return pounds > st.pounds;
  }

  bool Stonewt::operator>=(const Stonewt& st) const {
    return pounds >= st.pounds;
  }

  bool Stonewt::operator==(const Stonewt& st) const {
    return pounds == st.pounds;
  }

  bool Stonewt::operator!=(const Stonewt& st) const {
    return pounds != st.pounds;
  }

  std::ostream& operator<<(std::ostream& os, const Stonewt& wt) {
    switch(wt.state) {
    case STONE:
      cout << wt.stone << " stone, " << wt.pds_left << " pounds";
      break;
    case INT_LBS:
      cout << int(wt.pounds) << " pounds";
      break;
    case FLOAT_LBS:
    default:
      cout << wt.pounds << " pounds";
      break;
    }

    return os;
  }
}
