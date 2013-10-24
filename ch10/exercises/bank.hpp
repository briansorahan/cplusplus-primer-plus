// bank.hpp  - Class definitions for banks.

#include <iostream>

class Account {
private:
  enum { INSUFFICIENT_FUNDS = -1 };
  const char* name;
  const char* acctNumber;
  double balance;
public:
  // default constructor
  Account();
  Account(const char* name, const char* acctNumber);
  void show() const;
  // returns new balance
  double deposit(double amt);
  // returns new balance
  double withdraw(double amt);
};
