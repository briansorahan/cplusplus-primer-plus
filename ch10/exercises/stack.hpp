// stack.h -- class declaration for the stack ADT

#ifndef STACK_H_
#define STACK_H_

struct customer {
  char fullname[35];
  double payment;
};

typedef customer Item;

class Stack {
private:
  enum { MAX = 10 };     // constant specific to class
  Item items[MAX];       // holds stack items
  int top;               // index for top stack item
  double total;          // total payments that have been collected

public:
  Stack();
  bool isempty() const;
  bool isfull() const;

  // push returns false if stack is already full,
  // true otherwise
  bool push(const Item& item); // add item to stack

  // pop returns false if stack is already empty,
  // true otherwise
  // pop also adds customer's payment to the total
  bool pop(); // pop top into item
  double getTotal() const;
};

#endif
