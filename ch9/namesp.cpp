// namesp.cpp -- namespaces

#include<iostream>
#include "namesp.hpp"

namespace pers {
  using std::cout;
  using std::cin;

  void getPerson(Person& person) {
    cout << "Enter first name: ";
    cin >> person.first_name;
    cout << "Enter last name: ";
    cin >> person.last_name;
  }

  void showPerson(const Person& person) {
    cout << person.last_name << ", " << person.first_name;
  }
}

namespace debts {
  void getDebt(Debt& debt) {
    getPerson(debt.person);
    std::cout << "Enter debt: ";
    std::cin >> debt.amount;
  }

  void showDebt(const Debt& debt) {
    showPerson(debt.person);
    std::cout << ": $" << debt.amount << std::endl;
  }

  double sumDebts(const Debt arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
      total += arr[i].amount;
    }
    return total;
  }
}
