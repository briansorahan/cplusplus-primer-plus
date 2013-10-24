// Exercise 1 from Chapter 6 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cctype>

int main() {
  using std::cin;
  using std::cout;
  
  char ch;
  cin.get(ch);
  while (ch != '@') {
    if (isdigit(ch)) {
      // do nothing
    }
    else if (isupper(ch)) {
      cout.put(tolower(ch));
    }
    else if (islower(ch)) {
      cout.put(toupper(ch));
    }
    else {
      cout.put(ch);
    }

    cin.get(ch);
  }

  cout << "\n";
  return 0;
}
