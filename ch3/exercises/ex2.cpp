// Exercise 2 from Chapter 3 of C++ Primer

#include <iostream>

int main() {
  using namespace std;

  const int inches_per_foot = 12;
  const double meters_per_inch = 0.0254;
  const double lbs_per_kg = 2.2;

  int inches, feet, weight;
  cout << "Enter your height in feet and inches." << endl;
  cout << "Feet: ";
  cin >> feet;
  cout << "Inches: ";
  cin >> inches;
  cout << "Enter your weight in pounds: ";
  cin >> weight;

  int inches_height = (feet * inches_per_foot) + inches;
  double meters_height = inches_height * meters_per_inch;
  double kg_weight = weight / lbs_per_kg;
  double body_mass_index = kg_weight / (meters_height * meters_height);
  cout << "Your body mass index is " << body_mass_index << endl;

  return 0;
}
