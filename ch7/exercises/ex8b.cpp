// Exercise 8 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<string>

const int Seasons = 4;
const char* SeasonNames[] = {"Spring", "Summer", "Fall", "Winter"};

// A better way to do this
// enum Season {SPRING, SUMMER, FALL, WINTER}

struct SeasonalExpenses {
  double* forSeason;
};

// Enter expenses for each season
void fill(SeasonalExpenses*);

// Show expenses for each season
void show(const SeasonalExpenses*);

int main() {
  SeasonalExpenses* expenses = new SeasonalExpenses;
  expenses->forSeason = new double[Seasons];

  fill(expenses);
  show(expenses);

  delete expenses;
  return 0;
}

void fill(SeasonalExpenses* expenses) {
  using namespace std;
  for (int i = 0; i < Seasons; i++) {
    cout << "Enter " << SeasonNames[i] << " expenses: ";
    cin >> expenses->forSeason[i];
  }
}

void show(const SeasonalExpenses* expenses) {
  using namespace std;
  double total = 0.0;
  cout << "\nEXPENSES\n";
  for (int i = 0; i < Seasons; i++) {
    cout << SeasonNames[i] << ": $" << expenses->forSeason[i] << endl;
    total += expenses->forSeason[i];
  }
  cout << "Total Expenses: $" << total << endl;
}
