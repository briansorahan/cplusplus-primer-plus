// Exercise 7 from Chapter 8 of C++ Primer
// Brian Sorahan

#include<iostream>

// Template A
template <typename T> void SumArray(T arr[], int n);

// Template B
template <typename T> void SumArray(T* arr[], int n);

struct debts {
  char name[50];
  double amount;
};

int main() {
  using namespace std;

  int things[6] = {13, 31, 103, 301, 310, 130};

  struct debts mr_E[3] = {
    {"Ima Wolfe", 2400.0},
    {"Ura Foxe", 1300.0},
    {"Iby Stout", 1800.0}
  };

  double* pd[3];

  // set pointers to the amount members of the
  // structures in mr_E
  for (int i = 0; i < 3; i++) {
    pd[i] = &mr_E[i].amount;
  }

  cout << "Listing Mr. E's counts of things:\n";
  // things is an array of int
  SumArray(things, 6); // uses Template A

  // pd is an array of pointers to double
  SumArray(pd, 3); // uses Template B because it is more specialized

  return 0;
}

template <typename T> void SumArray(T arr[], int n) {
  using namespace std;
  T sum = arr[0];
  cout << "template A\n"
       << "----------\n";
  for (int i = 1; i < n; i++) {
    sum += arr[i];
  }
  cout << "Sum of things = " << sum << endl;
}

template <typename T> void SumArray(T* arr[], int n) {
  using namespace std;
  T sum = *arr[0];
  cout << "template B\n"
       << "----------\n";
  for (int i = 1; i < n; i++) {
    sum += *arr[i];
  }
  cout << "Sum of the debts = " << sum << endl;
}
