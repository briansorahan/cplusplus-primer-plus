// stock02.h -- augmented version
// version 02

#ifndef __STOCK02_H__
#define __STOCK02_H__

#include <string>

using std::ostream;

class Stock {
 private:
  char* company;
  int len; // length of the company name
  long shares;
  double share_val;
  double total_val;
  void set_tot() {
    total_val = shares * share_val;
  }
 public:
  Stock(); // default constructor
  Stock(const char* co, long n = 0, double pr = 0.0);
  ~Stock(); // destructor
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  const Stock& topval(const Stock& s) const;
  // overloaded operators
  Stock& operator=(const Stock&);
  friend ostream& operator<<(ostream&, const Stock&);
};

#endif
