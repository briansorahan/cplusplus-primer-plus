// queue.cpp -- Queue and Customer implementations

#include <cstdlib>
#include "queue.hpp"

////////////////////////////////////////////////////////////////////////////////
// Queue Methods
////////////////////////////////////////////////////////////////////////////////

Queue::Queue(int qs) : qsize(qs) {
  front = rear = NULL;
  items = 0;
}

Queue::~Queue() {
  Node* temp;
  while (front != NULL) {
    temp = front;
    front = front->next;
    delete temp;
  }
}

bool Queue::isempty() const {
  return items == 0;
}

bool Queue::isfull() const {
  return items == qsize;
}

int Queue::queuecount() const {
  return items;
}

// add item to queue
bool Queue::enqueue(const Item& item) {
  if (isfull())
    return false;

  Node* add = new Node;
  add->item = item;
  add->next = NULL;
  items++;

  if (front == NULL)
    front = add;
  else
    rear->next = add;

  rear = add;
  return true;
}

// place front item into item variable and remove from queue
bool Queue::dequeue(Item& item) {
  if (front == NULL)
    return false;

  item = front->item;
  items--;
  Node* temp = front;
  front = front->next;
  delete temp;

  if (items == 0)
    rear = NULL;

  return true;
}

////////////////////////////////////////////////////////////////////////////////
// Customer Methods
////////////////////////////////////////////////////////////////////////////////

// set arrival time to when,
// and set processingTime to random number between 1 and 3
void Customer::set(long when) {
  processTime = std::rand() % 3 + 1;
  arrive = when;
}
