// modulus.cpp -- uses % operator to convert lbs to stone

#include <iostream>

int main() {
  using namespace std;

  const int lbs_per_stone = 14;
  int lbs;

  cout << "Enter your weight in lbs: ";
  cin >> lbs;

  int stone = lbs / lbs_per_stone;
  int pounds = lbs % lbs_per_stone;
  cout << lbs << " pounds are " << stone
       << " stone, " << pounds << " pound(s).\n";

  return 0;
}
