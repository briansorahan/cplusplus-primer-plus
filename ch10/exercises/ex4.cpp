// Exercise 4 from Chapter 10 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include "sales.hpp"

int main() {
  using sales::Sales;

  const double arr[sales::QUARTERS] = { 100.0, 200.0, 35.0, 350.0 };
  Sales nonInteractive = Sales(arr, sales::QUARTERS);

  Sales interactive;
  interactive.setSales();

  nonInteractive.showSales();
  interactive.showSales();
    
  return 0;
}
