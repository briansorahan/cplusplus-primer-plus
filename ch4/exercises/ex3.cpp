// Exercise 3 from Chapter 4 of C++ Primer

#include <iostream>

int main() {
  using namespace std;

  const int MAX_LEN = 80;
  char first_name[MAX_LEN];
  char last_name[MAX_LEN];

  cout << "Enter your first name: ";
  cin.getline(first_name, MAX_LEN);
  cout << "Enter your last name: ";
  cin.getline(last_name, MAX_LEN);

  cout << "Here's the information in a single string: "
       << last_name << ", " << first_name << endl;

  return 0;
}
