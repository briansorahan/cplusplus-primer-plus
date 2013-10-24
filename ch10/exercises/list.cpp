// List class implementation
// Brian Sorahan

#include "list.hpp"

List::List() {
  tail = 0;
}

// Add an item to the list.
// Returns true on success, false otherwise.
bool List::add(T t) {
  if (this->isFull())
    return false;
  this->ts[tail++] = t;
  return true;
}

bool List::isEmpty() const {
  return tail == 0;
}

bool List::isFull() const {
  return tail == MAX;
}

// Execute a function for each item in the list.
void List::visit(void (*pf)(T)) {
  for (int i = 0; i < tail; i++)
    pf(ts[i]);
}
