// structur.cpp -- a simple structure

#include <iostream>

struct inflatable {
  char name[20];
  float volume;
  double price;
};

int main() {
  using namespace std;

  inflatable guest = {
    "Glorious Gloria",    // name
    1.88,                 // vol
    29.99                 // price
  };

  inflatable pal = {
    "Audacious Arthur",   // name
    3.12,                 // vol
    32.99                 // price
  };

  cout << "Expand your guest list with "
       << guest.name << " and "
       << pal.name << endl;

  cout << "You can have both for $"
       << guest.price + pal.price << endl;

  return 0;
}
