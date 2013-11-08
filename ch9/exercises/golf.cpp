// golf.cpp -- implementation of the function prototypes from golf.h
// Brian Sorahan

#include<iostream>
#include<cstring>
#include "golf.hpp"

// non-interactive version
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf& g, const char* name, int hc) {
  strcpy(g.fullname, name);
  g.handicap = hc;
}

// interactive version:
// solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf& g) {
  using std::cout;
  using std::cin;

  cout << "Enter name: ";
  cin.getline(g.fullname, LEN);

  if (strlen(g.fullname) == 0)
    return 0;

  cout << "Enter handicap: ";
  (cin >> g.handicap).get();

  return 1;
}

// resets handicap to new value
void handicap(golf& g, int hc) {
  g.handicap = hc;
}

// displays contents of golf structure
void showgolf(const golf& g) {
  std::cout << "Name:     " << g.fullname << std::endl
	    << "Handicap: " << g.handicap << std::endl;
}


