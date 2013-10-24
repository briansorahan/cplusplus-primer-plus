// pointer.cpp -- our first pointer variable

#include <iostream>

int main() {
  using namespace std;

  int updates = 6;
  int *p_updates = &updates;

  cout << "Values:" << endl
       << "  updates = " << updates << endl
       << "  *p_updates = " << *p_updates << endl;

  cout << "Addresses:" << endl
       << "  &updates = " << &updates << endl
       << "  p_updates = " << p_updates << endl;

  // use pointer to change value
  *p_updates = *p_updates + 1;
  cout << "Now updates = " << updates << endl;

  return 0;
}
