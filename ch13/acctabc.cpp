// acctabc.cpp -- bank account class implementations
#include <iostream>
#include "acctabc.hpp"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::AcctABC(const string& s, long an, double bal)
  : fullName(s), acctNum(an), balance(bal) {}

void AcctABC::Deposit(double amt) {
  if (amt < 0)
    cout << "Negative deposit not allowed; "
	 << "Deposit cancelled.\n";
  else
    balance += amt;
}

void AcctABC::Withdraw(double amt) {
  balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const {
  // set up ###.## format
  Formatting f;
  f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
  f.pr = cout.precision(2);
  return f;
}

void AcctABC::Restore(Formatting& f) const {
  cout.setf(f.flag, ios_base::floatfield);
  cout.precision(f.pr);
}

////////////////////////////////////////////////////////////////////////////////
// Brass methods
////////////////////////////////////////////////////////////////////////////////

void Brass::Withdraw(double amt) {
  if (amt < 0)
    cout << "Withdrawal amount must be positive; "
	 << "Withdrawal cancelled.\n";
  else if (amt <= Balance())
    AcctABC::Withdraw(amt);
  else
    cout << "Withdrawal amount of $" << amt
	 << " exceeds your balance.\n"
	 << "Withdrawal cancelled.\n";
}

void Brass::ViewAcct() const {
  Formatting f = SetFormat();
  cout << "Brass Client: " << FullName() << endl;
  cout << "Account Number: " << AcctNum() << endl;
  cout << "Balance: $" << Balance() << endl;
  Restore(f);
}

////////////////////////////////////////////////////////////////////////////////
// BrassPlus methods
////////////////////////////////////////////////////////////////////////////////

BrassPlus::BrassPlus(const string& s, long an, double bal,
		     double m1, double r) : AcctABC(s, an, bal) {
  maxLoan = m1;
  owesBank = 0.0;
  rate = r;
}

BrassPlus::BrassPlus(const Brass& br, double m1, double r) : AcctABC(br) {
  maxLoan = m1;
  owesBank = 0.0;
  rate = r;
}

void BrassPlus::ViewAcct() const {
  Formatting f = SetFormat();

  cout << "BrassPlus Client: " << FullName() << endl;
  cout << "Account Number: " << AcctNum() << endl;
  cout << "Balance: $" << Balance() << endl;
  cout << "Maximum Loan: $" << maxLoan << endl;
  cout << "Owed to bank: $" << owesBank << endl;
  cout.precision(3);
  cout << "Loan Rate: " << rate * 100 << endl;

  Restore(f);
}

void BrassPlus::Withdraw(double amt) {
  Formatting f = SetFormat();
  
  double bal = Balance();
  if (amt <= bal)
    AcctABC::Withdraw(amt);
  else if (amt <= bal + maxLoan - owesBank) {
    double advance = amt - bal;
    owesBank += advance * (1.0 + rate);
    cout << "Bank advance: $" << advance << endl;
    cout << "Finance charge: $" << advance * rate << endl;
    Deposit(advance);
    AcctABC::Withdraw(amt);
  }
  else
    cout << "Credit limit exceeded. Transaction cancelled.\n";

  Restore(f);
}
