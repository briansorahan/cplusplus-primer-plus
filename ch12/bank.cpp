// bank.cpp -- using the queue interface
// compile with queue.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.hpp"

const int MIN_PER_HR = 60;

// is there a new customer?
bool newcustomer(double x); 

int main() {

////////////////////////////////////////////////////////////////////////////////
// setup
////////////////////////////////////////////////////////////////////////////////

  using std::cin;
  using std::cout;
  using std::endl;
  using std::ios_base;

  // random initializing of rand()
  std::srand(std::time(0));

  cout << "Case Study: Bank of Heather Automatic Teller\n"
       << "Enter maximum size of queue: ";
  int qs;
  cin >> qs;
  Queue line(qs); // line holds up to qs customers

  cout << "Enter the number of simulation hours: ";
  int hours;
  cin >> hours;

  // simulation will run 1 cycle per minute
  long cycleLimit = MIN_PER_HR * hours;

  cout << "Enter the average number of customers per hour: ";
  double perhour;
  cin >> perhour;
  double min_per_cust; // average time between arrivals
  min_per_cust = MIN_PER_HR / perhour;

  Item temp;            // new customer data
  long turnaways = 0;   // turned away because of full queue
  long customers = 0;   // joined the queue
  long served = 0;      // served during the simulation
  long sumLine = 0;    // cumulative line length
  int waitTime = 0;    // time until autoteller is free
  long lineWait = 0;   // cumulative time in line

/////////////////////////////////////////////////////////////////////////////////
// run the simulation
////////////////////////////////////////////////////////////////////////////////

  for (int cycle = 0; cycle < cycleLimit; cycle++) {
    if (newcustomer(min_per_cust)) {
      if (line.isfull()) {
	turnaways++;
      } else {
	customers++;
	temp.set(cycle);      // cycle = time of arrival
	line.enqueue(temp);   // add newcomer to line
      }
    }

    if (waitTime <= 0 && line.isempty()) {
      line.dequeue(temp);              // attend next customer
      waitTime = temp.pTime();         // for waitTime minutes
      lineWait += cycle - temp.when();
      served++;
    }

    if (waitTime > 0)
      waitTime--;

    sumLine += line.queuecount();
  }

////////////////////////////////////////////////////////////////////////////////
// report the results
////////////////////////////////////////////////////////////////////////////////

  if (customers > 0) {
    cout << "customers accepted: " << customers << endl;
    cout << "  customers served: " << served << endl;
    cout << "         turnaways: " << turnaways << endl;
    cout << "average queue size: ";
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << (double) sumLine / cycleLimit << endl;
    cout << " average wait time: "
	 << (double) lineWait / served << " minutes\n";
  } else {
    cout << "No customers!\n";
  }

  cout << "Done.\n";
  return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) {
  return (std::rand() * x / RAND_MAX < 1);
}
