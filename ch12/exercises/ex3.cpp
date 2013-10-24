// Exercise 3 from Chapter 12 of C++ Primer Plus
// Brian Sorahan
// compile with stock02.cpp

#include <iostream>
#include "stock02.hpp"

const int STKS = 4;

int main() {
  using std::cout;

  // create an array of initialized objects
  Stock stocks[STKS] = {
    Stock("NanoSmart", 12, 20.0),
    Stock("Boffo Objects", 200, 2.0),
    Stock("Monolithic Obelisks", 130, 3.25),
    Stock("Fleep Enterprises", 60, 6.5)
  };

  cout << "Stock holdings:\n";
  int st;
  for (st = 0; st < STKS; st++) {
    cout << stocks[st];
  }

  // set pointer to first element
  const Stock* top = &stocks[0];
  for (st = 1; st < STKS; st++) {
    top = &top->topval(stocks[st]);
  }

  // now top points to the most valuable holding
  cout << "\nMost valuable holding:\n";
  cout << *top;

  return 0;
}
