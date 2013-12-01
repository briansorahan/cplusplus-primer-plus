// queue.hpp -- interface for a queue

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

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

#endif
