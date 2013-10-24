// cubes.cpp -- regular and reference arguments

#include<iostream>

double cube(double a);
double refcube(const double& ra);

int main() {
  using namespace std;

  double x = 3.0;

  cout << cube(x)
       << " = cube of " << x << endl;
  cout << refcube(x)
       << " = cube of " << x << endl;

  return 0;
}

double cube(double a) {
  a *= a * a;
  return a;
}

double refcube(const double& ra) {
  // ra *= ra * ra;
  // return ra;
  return ra * ra * ra;
}
