// file2.cpp -- example of a three-file program
#include<iostream>
#include<cmath>
#include "coordin.h"

// convert rectangular to polar coordinates
polar rect_to_polar(rect rpos) {
  using namespace std;
  polar result;

  result.distance = sqrt(rpos.x * rpos.x + rpos.y * rpos.y);
  result.angle = atan2(rpos.y, rpos.x);

  return result;
}

// show polar coordinates, converting angle to degrees
void show_polar(polar ppos) {
  using namespace std;
  const double Rad_to_deg = 57.29577951;

  cout << "distance = " << ppos.distance
       << ", angle = " << ppos.angle * Rad_to_deg
       << " degress" << endl;
}
