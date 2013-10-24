// twoswap.cpp -- specialization overrides a template

#include<iostream>

template <typename T> void Swap(T& a, T& b);

struct job {
  char name[40];
  double salary;
  int floor;
};

// explicit specialization
template <> void Swap<job>(job&, job&);

void Show(job&);

int main() {
  using namespace std;

  cout.precision(2);
  cout.setf(ios::fixed, ios::floatfield);

  int i = 10;
  int j = 20;
  cout << "i, j = " << i << ", " << j << ".\n";
  cout << "Using compiler-generated int swapper:\n";
  Swap(i, j); // generates void Swap(int&, int&)
  cout << "Now i, j = " << i << ", " << j << ".\n";

  job sue = {"Susan Yaffee", 73000.60, 7};
  job sidney = {"Sidney Yaffee", 78060.72, 9};
  cout << "Before job swapping:\n";
  Show(sue);
  Show(sidney);
  Swap(sue, sidney); // uses specialization
  cout << "After job swapping:\n";
  Show(sue);
  Show(sidney);

  return 0;
}

template <typename T> void Swap(T& a, T& b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

// Swap the salary and floor fields of a job structure
template <> void Swap<job>(job& j1, job& j2) {
  // Swap salary
  double tempSalary = j1.salary;
  j1.salary = j2.salary;
  j2.salary = tempSalary;

  // Swap floor
  int tempFloor = j1.floor;
  j1.floor = j2.floor;
  j2.floor = tempFloor;
}

void Show(job& j) {
  using namespace std;
  cout << j.name << ": $" << j.salary
       << " on floor " << j.floor << endl;
}
