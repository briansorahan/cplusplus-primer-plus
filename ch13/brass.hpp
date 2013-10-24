// brass.hpp -- Bank Account classes
#ifndef __BRASS_HPP__
#define __BRASS_HPP__

#include <string>

class Brass {
private:
  std::string fullName;
  long acctNum;
  double balance;
public:
  Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
  void Deposit(double amt);
  virtual void Withdraw(double amt);
  double Balance() const;
  virtual void ViewAcct() const;
  virtual ~Brass() {}
};

class BrassPlus : public Brass {
private:
  double maxLoan;
  double rate;
  double owesBank;
public:
  BrassPlus(const std::string& s = "Nullbody", long an = -1,
	    double bal = 0.0, double m1 = 500, double r = 0.11125);
  BrassPlus(const Brass& br, double m1 = 500, double r = 0.11125);
  virtual void ViewAcct() const;
  virtual void Withdraw(double amt);
  void ResetMax(double m) { maxLoan = m; }
  void ResetRate(double r) { rate = r; }
  void ResetOwes() { owesBank = 0; }
};

#endif
