// Exercise 4 from Chapter 4 of C++ Primer
// Note: This is the same program as Exercise 3,
// but we use std::string instead of char[].

#include <iostream>

int main() {
  using namespace std;

  string first_name;
  string last_name;

  cout << "Enter your first name: ";
  getline(cin, first_name);
  cout << "Enter your last name: ";
  getline(cin, last_name);

  cout << "Here's the information in a single string: "
       << last_name << ", " << first_name << endl;

  return 0;
}
