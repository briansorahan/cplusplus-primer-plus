// Exercise 1 from Chapter 4 of C++ Primer

#include <iostream>

int main() {
  using namespace std;

  const int MAX_LENGTH = 80;
  char first_name[MAX_LENGTH];
  char last_name[MAX_LENGTH];
  char grade;
  int age;

  cout << "What is your first name? ";
  cin.getline(first_name, MAX_LENGTH);
  cout << "What is your last name? ";
  cin.getline(last_name, MAX_LENGTH);
  cout << "What letter grade do you deserve? ";
  cin >> grade;
  cout << "What is your age? ";
  cin >> age;

  // Give them a worse grade
  grade = grade + 1;

  cout << "Name: " << last_name
       << ", " << first_name << endl;
  cout << "Grade: " << grade << endl;
  cout << "Age: " << age << endl;

  return 0;
}
