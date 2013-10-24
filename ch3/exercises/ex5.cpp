// Exercise 5 from Chapter 3 of C++ Primer

#include <iostream>

int main() {
  using namespace std;

  long long world_population, usa_population;
  cout << "Enter the worlds's population: ";
  cin >> world_population;
  cout << "Enter the population of the United States: ";
  cin >> usa_population;

  double americanization =
    double(usa_population) / double(world_population) * 100.0;

  cout << "The population of the US is "
       << americanization << "%"
       << " of the world population."
       << endl;

  return 0;
}
