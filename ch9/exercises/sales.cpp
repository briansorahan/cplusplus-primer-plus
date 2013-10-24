// sales.cpp -- function definitions for Sales

#include<iostream>
#include "sales.h"

namespace sales {
  // copies the lesser of 4 or n items from the
  // array to the sales member of s and computes
  // and stores the average, max, and min values
  // of the entered items
  // remaining elements of sales, if any, are
  // set to 0
  void setSales(Sales& s, const double arr[], int n) {
    if (n > sales::QUARTERS)
      n = sales::QUARTERS;

    double total = 0.0;
    double min = arr[0];
    double max = arr[0];

    for (int i = 0; i < n; i++) {
      s.sales[i] = arr[i];
      total += arr[i];
      min = arr[i] < min ? arr[i] : min;
      max = arr[i] > max ? arr[i] : max;
    }

    s.average = total / n;
    s.min = min;
    s.max = max;

    return;
  }

  // gathers sales for 4 quarters interactively,
  // stores them in the sales member of s and
  // computes and stores the average, max, and
  // min values
  void setSales(Sales& s) {
    using std::cin;
    using std::cout;

    cout << "Enter sales (q to quit):\n";
    double* sales = new double[sales::QUARTERS];

    int i = 0;
    while (i < sales::QUARTERS && cin >> sales[i]) {
      i++;
    }
  
    setSales(s, sales, i);
    return;
  }

  // display all information for this Sales object
  void showSales(const Sales& s, int numSales) {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Sales:\n";
    for (int i = 0; i < numSales; i++) {
      cout << "\tQ1: " << s.sales[i] << endl;
    }

    cout << "\tAverage:  " << s.average << endl;
    cout << "\tMin:      " << s.min << endl;
    cout << "\tMax:      " << s.max << endl;

    return;
  }
}
