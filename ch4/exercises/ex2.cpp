// Exercise 2 from Chapter 4 of C++ Primer
// Note: This is the same program as Exercise 1, just using
// std::string instead of char[].

#include <iostream>

int main() {
  using namespace std;

  string first_name;
  string last_name;
  char grade;
  int age;

  cout << "What is your first name? ";
  getline(cin, first_name);
  cout << "What is your last name? ";
  getline(cin, last_name);
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
