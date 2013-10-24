// Exercise 1 from Chapter 10 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include "bank.hpp"

int main() {
  Account acct("Super Mega Corp", "123456789");
  acct.show();
  acct.deposit(1000000.0);
  std::cout << "After today's deposit, new account info is...\n";
  acct.show();
  // world.destroy();
  acct.withdraw(999999.0);
  std::cout << "The world economy crashed today. New balance is...\n";
  acct.show();
  std::cout << "In a desperate run on the bank, the balance becomes...\n";
  double result = acct.withdraw(2000000);
  std::cout << result << "\n";

  return 0;
}
