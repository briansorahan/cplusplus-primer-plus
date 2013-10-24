// bank.cpp -- Implementation of the bank classes.

#include <iostream>
#include "bank.hpp"

// default constructor
Account::Account() {
  this->name = "";
  this->acctNumber = "";
  this->balance = 0.0;
}

Account::Account(const char* name, const char* acctNumber) {
  this->name = name;
  this->acctNumber = acctNumber;
  this->balance = 0.0;
}

void Account::show() const {
  using std::cout;
  cout << this->name << ":\n";
  cout << "\tAccount:   " << this->acctNumber << "\n";
  cout << "\tBalance:   " << this->balance << "\n";
}

// returns new balance
double Account::deposit(double amt) {
  return this->balance += amt;
}

// returns new balance
double Account::withdraw(double amt) {
  if (amt > this->balance) {
    return INSUFFICIENT_FUNDS;
  }
  else {
    return this->balance -= amt;
  }
}
