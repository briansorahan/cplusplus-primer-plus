// sales.cpp -- function definitions for Sales

#include<iostream>
#include "sales.hpp"

namespace sales {
  Sales::Sales() {
  }

  Sales::Sales(const double arr[], int n) {
    n = n > QUARTERS ? QUARTERS : n;
    double total = 0.0;
    double minimum = arr[0];
    double maximum = arr[0];

    for (int i = 0; i < n; i++) {
      sales[i] = arr[i];
      total += arr[i];
      minimum = arr[i] < minimum ? arr[i] : minimum;
      maximum = arr[i] > maximum ? arr[i] : maximum;
    }

    this->min = minimum;
    this->max = maximum;
    this->average = total / n;
    
    return;
  }

  // copies the lesser of 4 or n items from the
  // array to the sales member of s and computes
  // and stores the average, max, and min values
  // of the entered items
  // remaining elements of sales, if any, are
  // set to 0
  void Sales::setSales(const double arr[], int n) {
    *this = Sales(arr, n);
  }

  // gathers sales for 4 quarters interactively,
  // stores them in the sales member of s and
  // computes and stores the average, max, and
  // min values
  void Sales::setSales() {
    using std::cin;
    using std::cout;

    cout << "Enter sales (q to quit):\n";
    double* arr = new double[QUARTERS];

    int i = 0;
    while (i < QUARTERS && cin >> arr[i]) {
      i++;
    }
  
    this->setSales(arr, i);

    return;
  }

  // display all information for this Sales object
  void Sales::showSales(int numSales) const {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Sales:\n";
    for (int i = 0; i < numSales; i++) {
      cout << "\tQ1: " << this->sales[i] << endl;
    }

    cout << "\tAverage:  " << this->average << endl;
    cout << "\tMin:      " << this->min << endl;
    cout << "\tMax:      " << this->max << endl;

    return;
  }
}
