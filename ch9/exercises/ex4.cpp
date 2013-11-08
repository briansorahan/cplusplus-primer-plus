// Exercise 4 from Chapter 9 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include "sales.hpp"

int main() {
  using namespace sales;

  Sales* first  = new Sales;
  Sales* second = new Sales;
  const double sales[QUARTERS] =
    { 400.0, 500.0, 180.0, 320.0 };

  setSales(*first);
  setSales(*second, sales, QUARTERS);

  showSales(*first);
  showSales(*second);

  delete first;
  delete second;
  
  return 0;
}
