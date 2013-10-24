// usebrass2.cpp -- polymorphic example
// compile with brass.cpp
#include <iostream>
#include <string>
#include "brass.hpp"

const int CLIENTS = 4;

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  Brass* p_clients[CLIENTS];
  std::string temp;
  long tempnum;
  double tempbal;
  char kind;
  for (int i = 0; i < CLIENTS; i++) {
    cout << "Enter client's name: ";
    getline(cin, temp);
    // cin.get();
    cout << "Enter client's account number: ";
    cin >> tempnum;
    // cin.get();
    cout << "Enter opening balance: ";
    cin >> tempbal;
    cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
    while (cin >> kind && (kind != '1' && kind != '2')) {
      cout << "Please enter either 1 or 2: ";
    }
    switch(kind) {
    case '1':
      p_clients[i] = new Brass(temp, tempnum, tempbal);
      break;
    case '2':
      double tempmax, temprate;
      cout << "Enter the overdraft limit: $";
      cin >> tempmax;
      cout << "Enter the interest rate as a decimal fraction: ";
      cin >> temprate;
      p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tempmax, temprate);
      break;
    }
    while (cin.get() != '\n')
      continue;
  }

  cout << endl;
  for (int i = 0; i < CLIENTS; i++) {
    p_clients[i]->ViewAcct();
    cout << endl;
  }

  for (int i = 0; i < CLIENTS; i++) {
    delete p_clients[i];
  }

  cout << "Done.\n";
  return 0;
}
