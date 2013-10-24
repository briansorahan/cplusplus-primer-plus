// Exercise 6 from Chapter 4 of C++ Primer

#include <iostream>

struct candy_bar {
  std::string brand_name;
  double weight;
  int calories;
};

void print(candy_bar*);

int main() {
  candy_bar snacks[3];

  snacks[0] = {
    "Mocha Munch", // brand name
    2.3,           // weight
    350            // calories
  };

  snacks[1] = {
    "Tutti Frutti", // brand name
    0.6,            // weight
    217             // calories
  };

  snacks[2] = {
    "Jolly Rancher", // brand name
    1.2,             // weight
    433              // calories
  };

  std::cout << "Three snacks:" << std::endl;
  print(&snacks[0]);
  print(&snacks[1]);
  print(&snacks[2]);

  return 0;
}

void print(candy_bar* candy_bar) {
  std::cout << "{\"candy_bar\":{\"brand_name\":\""
            << candy_bar->brand_name << "\","
            << "\"weight\":" << candy_bar->weight << ","
            << "\"calories\":" << candy_bar->calories << "}}"
            << std::endl;
  return;
}
