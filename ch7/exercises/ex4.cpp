// Exercise 4 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

// Calculate the probability of winning a lotto
// where you get n picks from p possible numbers,
// and you have to guess the mega number correctly.
long double probability(unsigned n, unsigned p, unsigned mega);

int main() {
  using namespace std;

  unsigned picks = 5;
  unsigned total = 47;
  unsigned mega = 27;

  cout << "The probability of guessing " << picks
       << " out of " << total << " correctly, "
       << "plus the mega (out of " << mega << ") is "
       << probability(picks, total, mega) << endl;

  return 0;
}

long double probability(unsigned n, unsigned p, unsigned mega) {
  double prob = 1.0;

  for ( unsigned picks; n > 0; n--, p--) {
    prob *= (double) n / (double) p;
  }

  prob *= (double) 1 / (double) mega;
  return prob;
}
