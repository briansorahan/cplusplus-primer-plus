// Exercise 1 from Chapter 9 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include "golf.h"

int main() {
  using std::cout;
  using std::cin;
  using std::endl;

  const int MAX_GOLFERS = 1000;
  golf* golfers = new golf[MAX_GOLFERS];
  
  int result = 1, i = 0;
  while (i < MAX_GOLFERS && result != 0) {
    result = setgolf( golfers[i++] );
  }

  cout << "Here are the golfers:\n";
  for (int j = 0; j < i - 1; j++) {
    showgolf( golfers[j] );
  }

  delete [] golfers;
  return 0;
}
