// queue.hpp -- interface for a queue

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

class Customer {
private:
  long arrive;        // arrival time for customer
  int processTime;    // processing time for customer
public:
  Customer() { arrive = processTime = 0; }
  void set(long when);
  long when() const { return arrive; }
  int pTime() const { return processTime; }
};

typedef Customer Item;

class Queue {
private:
  // Linked-list node
  struct Node { Item item; struct Node* next; };
  enum { Q_SIZE = 10 };
  Node* front;
  Node* rear;
  int items;
  const int qsize;
  // preemptive definitions to prevent public copying
  Queue(const Queue& q) : qsize(0) {}
  Queue& operator=(const Queue& q) { return *this; }
public:
  Queue(int qs = Q_SIZE);
  ~Queue();
  bool isempty() const;
  bool isfull() const;
  int queuecount() const;
  // add item to end
  bool enqueue(const Item& item);
  // remove item from front
  bool dequeue(Item& item);
};

#endif
