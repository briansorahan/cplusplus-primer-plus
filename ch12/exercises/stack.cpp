// stack.cpp -- implementation for the stack ADT

#include <iostream>
#include "stack.hpp"

using std::cout;
using std::endl;

Stack::Stack(int n) {
  if (n > MAX) {
    cout << "Can't create a stack with more than "
	 << MAX << " elements." << endl
	 << "Initializing stack with " << MAX
	 << " elements" << endl;
    n = MAX;
  }

  pitems = new Item[n];
  size = 0;
  top = 0;
}

Stack::Stack(const Stack& st) {
  size = st.size;
  pitems = new Item[size];
  for (int i = 0; i < size; i++) {
    pitems[i] = st.pitems[i];
  }
  top = st.top;
}

Stack::~Stack() {
  delete [] pitems;
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

  pitems[top++] = item;
  size++;
  return true;
}

// pop returns false if stack is already empty,
// true otherwise
bool Stack::pop(Item& item) {
  if (top == 0) {
    return false;
  }

  item = pitems[--top];
  size--;
  return true;
}

Stack& Stack::operator=(const Stack& st) {
  if (this == &st) return *this;
  delete [] pitems;
  size = st.size;
  pitems = new Item[size];
  for (int i = 0; i < size; i++) {
    pitems[i] = st.pitems[i];
  }
  top = st.top;
  return *this;
}
