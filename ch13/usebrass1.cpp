// usebrass1.cpp -- testing the bank account classes
// compile with brass.cpp
#include <iostream>
#include "brass.hpp"

int main() {
  using std::cout;
  using std::endl;

  Brass Piggy("Porcelot Pigg", 381299, 4000.00);
  BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
  Piggy.ViewAcct();
  cout << endl;
  Hoggy.ViewAcct();
  cout << endl;
  double depositAmt = 1000.0;
  cout << "Depositing $" << depositAmt << " into the Hogg Account:\n";
  Hoggy.Deposit(depositAmt);
  cout << "New balance: $" << Hoggy.Balance() << endl;
  double withdrawAmt = 4200.0;
  cout << "Withdrawing $" << withdrawAmt << " from the Pigg Account:\n";
  Piggy.Withdraw(withdrawAmt);
  cout << "Pigg account balance: $" << Piggy.Balance() << endl;
  cout << "Withdrawing $" << withdrawAmt << " from the Hogg Account:\n";
  Hoggy.Withdraw(withdrawAmt);
  Hoggy.ViewAcct();

  return 0;
}
