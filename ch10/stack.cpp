// stack.cpp -- implementation for the stack ADT

#include "stack.h"

Stack::Stack() {
  top = 0;
}

bool Stack::isempty() const {
  return top == 0;
}

bool Stack::isfull() const {
  return top == MAX;
}

// push returns false if stack is already full,
// true otherwise
bool Stack::push(const Item& item) {
  if (top == MAX) {
    return false;
  }

  items[top++] = item;
  return true;
}

// pop returns false if stack is already empty,
// true otherwise
bool Stack::pop(Item& item) {
  if (top == 0) {
    return false;
  }

  item = items[top--];
  return true;
}
