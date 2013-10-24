// Exercise 8 from Chapter 4 of C++ Primer

#include <iostream>

struct pizza {
  std::string company;
  double diameter;
  double weight;
};

void print(pizza*);

int main() {
  using namespace std;

  pizza* pie = new pizza;

  cout << "Enter the name of the pizza company: ";
  getline(cin, pie->company);
  cout << "Enter the diameter of the pizza: ";
  cin >> pie->diameter;
  cout << "Enter the weight of the pizza: ";
  cin >> pie->weight;

  cout << "You entered:" << endl;
  print(pie);

  delete pie;

  return 0;
}

void print(pizza* pizza) {
  using namespace std;
  cout << "{\"pizza\":{"
       << "\"company\":\"" << pizza->company << "\""
       << ",\"diameter\":" << pizza->diameter
       << ",\"weight\":" << pizza->weight
       << "}}" << endl;
  return;
}
