// Exercise 5 from Chapter 10 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include "stack.hpp"

int main() {
  using std::cout;

  customer bob = {
    "bob let",
    20.0
  };

  customer sue = {
    "tu do",
    50.0
  };

  Stack stack;

  if (stack.push(bob)) {
    cout << "Pushed bob onto the stack.\n";
  }

  if (stack.push(sue)) {
    cout << "Pushed sue onto the stack.\n";
  }

  if (stack.pop()) {
    cout << "Total after popping sue = " << stack.getTotal() << "\n";
  }
  else {
    cout << "Could not pop sue from the stack.\n";
  }

  if (stack.pop()) {
    cout << "Total after popping bob = " << stack.getTotal() << "\n";
  }
  else {
    cout << "Could not pop bob from the stack.\n";
  }

  return 0;
}
