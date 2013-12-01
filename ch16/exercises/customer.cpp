// queue.cpp -- Queue and Customer implementations

#include <cstdlib>
#include "customer.hpp"

// set arrival time to when,
// and set processingTime to random number between 1 and 3
void Customer::set(long when) {
  processTime = std::rand() % 3 + 1;
  arrive = when;
}
