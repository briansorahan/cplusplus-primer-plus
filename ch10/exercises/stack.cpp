// stack.cpp -- implementation for the stack ADT

#include <iostream>
#include "stack.hpp"

Stack::Stack() {
  top = 0;
  total = 0.0;
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
bool Stack::pop() {
  if (top == 0) {
    return false;
  }

  Item i = items[--top];
  total += i.payment;

  return true;
}

double Stack::getTotal() const {
  return this->total;
}
