// Exercise 4 from Chapter 8 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>

using namespace std;

struct stringy {
  char* str;    // a character string
  int ct;       // length of string (not counting '\0')
};

void set(stringy&, char[]);
void show(const stringy&, const int n = 1);
void show(const char*, const int n = 1);

int main() {
  stringy beany;
  char testing[] = "Reality isn't what it used to be.";

  set(beany, testing); // first argument is a reference
  show(beany);
  show(beany, 2);

  testing[0] = 'D';
  testing[1] = 'u';

  show(testing);
  show(testing, 3);

  return 0;
}

void set(stringy& s, char* str) {
  stringy* newStringy = new stringy;
  int i = 0;

  while (str[i] != '\0') {
    i++;
  }

  newStringy->str = str;
  newStringy->ct = i;
  s = *newStringy;
}

void show(const stringy& s, const int n) {
  for (int i = 0; i < n; i++) {
    cout << "stringy: str=" << s.str
	 << "\tct=" << s.ct << endl;
  }
}

void show(const char* str, const int n) {
  for (int i = 0; i < n; i++) {
    cout << "string: " << str << endl;
  }
}
