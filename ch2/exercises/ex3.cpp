// Exercise 3 from Chapter 2 of C++ Primer
//
#include <iostream>

void print_actor();
void print_action();

int main() {
  print_actor();
  print_actor();

  print_action();
  print_action();
}

void print_actor() {
  using namespace std;
  cout << "Three blind mice" << endl;
}

void print_action() {
  using namespace std;
  cout << "See how they run" << endl;
}

