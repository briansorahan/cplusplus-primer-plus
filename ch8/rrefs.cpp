// rrefs.cpp -- rvalue references

#include<iostream>

int main() {
  using namespace std;

  // This works
  double && rref = 36.0;

  // This doesn't
  // double & rref_nfg = 36.0;

  return 0;
}
