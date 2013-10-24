// List interface
// Brian Sorahan

#ifndef LIST_H_
#define LIST_H_

struct platypus {
  char name[80];
  int age;
};

typedef platypus T;

class List {
private:
  static const int MAX = 1000;
  T ts[MAX];
  int tail;
public:
  List();
  // Add an item to the list
  bool add(T);
  bool isEmpty() const;
  bool isFull() const;
  // Execute a function for each item in the list.
  void visit(void (*pf)(T));
};

#endif
