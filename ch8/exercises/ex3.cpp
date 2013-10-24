// Exercise 3 from Chapter 8 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string& upcase(string& s);

int main() {
  string s;
  const char* prompt = "Enter a string (q to quit): ";
  cout << prompt;
  getline(cin, s);

  while(s != "q") {
    cout << upcase(s) << endl;
    cout << prompt;
    getline(cin, s);
  }

  cout << "Bye.\n";
  return 0;
}

string& upcase(string& s) {
  int i = 0;
  while (s[i] != '\0') {
    s[i] = toupper(s[i]);
    i++;
  }

  return s;
}
