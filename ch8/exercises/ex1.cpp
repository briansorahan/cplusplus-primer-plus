// Exercise 1 from Chapter 8 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<string>

// Print a string once
void printer(const char* s, int n = 1);

int main() {
  using namespace std;

  printer("once");
  printer("thrice", 3);

  return 0;
}

// Print a string n times.
// n defaults to 1.
void printer(const char* s, int n) {
  using namespace std;
  for (int i = 0; i < n; i++) {
    cout << s << endl;
  }
}
