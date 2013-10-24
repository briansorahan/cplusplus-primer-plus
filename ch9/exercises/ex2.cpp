// Exercise 2 from Chapter 9 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int ArrSize = 10;

void strcount(const string&);

int main() {
  string input;

  cout << "Enter a line:\n";
  // cin >> input;
  getline(cin, input);

  while (input != "") {
    strcount(input);
    cout << "Enter next line (empty line to quit):\n";
    getline(cin, input);
    // cin >> input;
  }

  cout << "Bye.\n";
  return 0;
}

void strcount(const string& str) {
  static int total = 0;
  int count = 0;

  cout << "\"" << str << "\" contains ";
  while (str[count] != '\0') {
    count++;
  }
  total += count;
  cout << count << " characters\n";
  cout << total << " characters total\n";
}
