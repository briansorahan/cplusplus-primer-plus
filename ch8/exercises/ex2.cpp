// Exercise 2 from Chapter 8 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

struct CandyBar {
  const char* name;
  double weight;
  int calories;
};

// Set all the members of a CandyBar structure.
CandyBar& set(CandyBar&,
	      const char* nm = "Millennium Munch",
	      double wt = 2.85,
	      int cal = 350);

// Display a CandyBar structure on stdout.
void show(CandyBar&);

int main() {
  CandyBar* c = new CandyBar;
  show(set(*c));
  delete c;
  return 0;
}

CandyBar& set(CandyBar& c, const char* nm, double wt, int cal) {
  c.name = nm;
  c.weight = wt;
  c.calories = cal;
  return c;
}

void show(CandyBar& c) {
  using namespace std;
  cout << c.name << ":\n";
  cout << "    weight: " << c.weight << endl;
  cout << "  calories: " << c.calories << endl;
}
