// Exercise 4 from Chapter 6 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

// Function prototypes
void showmenu();

// Benevolent Order of Programmers name structure
const int strsize = 80;
struct bop {
  char fullname[strsize];   // real name
  char title[strsize];      // job title
  char bopname[strsize];    // secret BOP name
  int preference;           // 0: fullname, 1: title, 2: bopname
};

enum {
  BOP_PREF_FULLNAME,   // Display by fullname
  BOP_PREF_TITLE,      // Display by title
  BOP_PREF_BOPNAME,    // Display by bopname
  BOP_PREF_PREFERENCE  // Display by preference
};

// Display BOP info
void displayBop(bop bops, int bop_pref);
void displayBops(bop* bops, int bop_pref);

int main() {
  using std::cin;
  using std::cout;

  // BOP Roster
  bop programmers[4] = {
    {
      "Brian Sorahan",
      "President",
      "wjoojoo",
      2
    },
    {
      "Sam Bagot",
      "Royal Jester",
      "dsmurl",
      1
    },
    {
      "Ben Meuer",
      "Lover of Glam",
      "lilbenny",
      0
    },
    {
      "Jeremy Gooch",
      "Artist of the Court",
      "junit",
      2
    }
  };

  showmenu();

  char choice;
  cin >> choice;
  while (choice != 'q') {
    switch (choice) {
    case 'a':
      displayBops(programmers, BOP_PREF_FULLNAME);
      break;
    case 'b':
      displayBops(programmers, BOP_PREF_TITLE);
      break;
    case 'c':
      displayBops(programmers, BOP_PREF_BOPNAME);
      break;
    case 'd':
      displayBops(programmers, BOP_PREF_PREFERENCE);
      break;
    default:
      break;
    }

    showmenu();
    cin >> choice;
  }

  return 0;
}

void showmenu() {
  using std::cout;
  cout << "Benevolent Order of Programmers Report:\n"
    "a) display by name              b) display by title\n"
    "c) display by bopname           d) display by preference\n"
    "q) quit\n";
}

void displayBops(bop* bops, int bop_pref) {
  using std::cout;
  int numBops = sizeof bops;

  cout << "\n***\n";

  for (int i = 0; i < numBops; i++) {
    displayBop(bops[i], bop_pref);
  }

  cout << "***\n\n";
}

void displayBop(bop b, int bop_pref) {
  using std::cout;

  switch (bop_pref) {
  case BOP_PREF_FULLNAME:
    cout << b.fullname << "\n";
    break;
  case BOP_PREF_TITLE:
    cout << b.title << "\n";
    break;
  case BOP_PREF_BOPNAME:
    cout << b.bopname << "\n";
    break;
  case BOP_PREF_PREFERENCE:
    displayBop(b, b.preference);
    break;
  }
}
