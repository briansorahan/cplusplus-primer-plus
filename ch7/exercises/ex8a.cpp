// Exercise 8 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<string>

const int Seasons = 4;
const char* SeasonNames[] = {"Spring", "Summer", "Fall", "Winter"};

// Enter expenses for each season
void fill(double pa[]);

// Show expenses for each season
void show(const double da[]);

int main() {
  double* expenses = new double[Seasons];

  fill(expenses);
  show(expenses);

  delete [] expenses;
  return 0;
}

void fill(double pa[]) {
  using namespace std;
  for (int i = 0; i < Seasons; i++) {
    cout << "Enter " << SeasonNames[i] << " expenses: ";
    cin >> pa[i];
  }
}

void show(const double da[]) {
  using namespace std;
  double total = 0.0;
  cout << "\nEXPENSES\n";
  for (int i = 0; i < Seasons; i++) {
    cout << SeasonNames[i] << ": $" << da[i] << endl;
    total += da[i];
  }
  cout << "Total Expenses: $" << total << endl;
}
