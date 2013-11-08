// golf.h -- header file for Exercise 1 from Chapter 9 of C++ Primer Plus

const int LEN = 40;

struct golf {
  char fullname[LEN];
  int handicap;
};

// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf& g, const char* name, int hc);

// interactive version:
// solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf& g);

// resets handicap to new value
void handicap(golf& g, int hc);

// displays contents of golf structure
void showgolf(const golf& g);


