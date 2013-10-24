// external.cpp -- external variables
// compile with support.cpp
#include<iostream>
using namespace std;
// external variable
double warming = 0.3; // warming defined

void update(double dt);
void local();

int main() {
  cout << "Global warming is " << warming
       << " degrees.\n";
  update(0.1);
  cout << "Global warming is " << warming
       << " degrees.\n";
  local();
  cout << "Global warming is " << warming
       << " degrees.\n";

  return 0;
}
