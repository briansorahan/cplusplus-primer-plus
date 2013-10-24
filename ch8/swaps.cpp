// swaps.cpp -- swapping with references and with pointers

#include<iostream>

// a and b are aliases for ints
void swapr(int & a, int & b);

// p and q are addresses of ints
void swapp(int* p, int* q);

// a and b are new variables
void swapv(int a, int b);

int main() {
  using namespace std;

  int wallet1 = 300;
  int wallet2 = 500;

  cout << "wallet1 = $" << wallet1
       << ", wallet2 = $" << wallet2 << endl;

  cout << "Using references to swap contents:\n";
  swapr(wallet1, wallet2);
  cout << "wallet1 = $" << wallet1
       << ", wallet2 = $" << wallet2 << endl;

  cout << "Using pointers to swap contents:\n";
  swapp(&wallet1, &wallet2);
  cout << "wallet1 = $" << wallet1
       << ", wallet2 = $" << wallet2 << endl;

  cout << "Trying to use pass by value:\n";
  swapv(wallet1, wallet2);
  cout << "wallet1 = $" << wallet1
       << ", wallet2 = $" << wallet2 << endl;

  return 0;
}

void swapr(int& a, int& b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void swapp(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void swapv(int a, int b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}
