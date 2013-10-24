// Exercise 3 from Chapter 6 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

// function prototypes
void showmenu();

int main() {
  using std::cin;
  using std::cout;

  showmenu();
  char choice;
  cin >> choice;
  while (choice != 'q') {
    switch (choice) {
    case 'c' : cout << "Carnivores are dangerous!\n";
      break;
    case 'p' : cout << "Pianists make beautiful sounds!\n";
      break;
    case 't' : cout << "Trees are gentle giants!\n";
      break;
    case 'g' : cout << "Games are so much fun!\n";
      break;
    }

    cin >> choice;
  }
  
  cout << "Goodbye!\n";
  return 0;
}

void showmenu() {
  using std::cout;
  cout << "Please enter one of the following choices:\n"
          "c) carnivore              p) pianist\n"
          "t) tree                   g) game\n"
          "q) quit\n";
}
