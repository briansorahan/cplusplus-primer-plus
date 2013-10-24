// Exercise 5 from Chapter 4 of C++ Primer

#include <iostream>

struct candy_bar {
  std::string brand_name;
  double weight;
  int calories;
};

void print_candy_bar(candy_bar*);

int main() {
  candy_bar snack = {
    "Mocha Munch", // brand name
    2.3,           // weight
    350            // calories
  };

  print_candy_bar(&snack);

  return 0;
}

void print_candy_bar(candy_bar* candy_bar) {
  std::cout << "{\"candy_bar\":{\"brand_name\":\""
            << candy_bar->brand_name << "\","
            << "\"weight\":" << candy_bar->weight << ","
            << "\"calories\":" << candy_bar->calories << "}}"
            << std::endl;
  return;
}
