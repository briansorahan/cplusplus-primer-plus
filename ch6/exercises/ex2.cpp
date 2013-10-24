// Exercise 2 from Chapter 6 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

int main() {
  using std::cin;
  using std::cout;
  
  const int MAX_DONATIONS = 10;
  double* donations = new double[MAX_DONATIONS];

  cout << "Please enter the donation amounts one line at a time:\n"
       << "(Maximum is 10 donations)\n";
  
  int numDonations = 0;
  double total = 0.0;
  while (numDonations < MAX_DONATIONS
	 && (cin >> donations[numDonations])) {
    total += donations[numDonations];
    numDonations++;
  }

  double avg = total / (double) numDonations;
  int numLarger = 0; // number of donations larger than the average
  for (int i = 0; i < numDonations; i++) {
    if (donations[i] > avg) {
      numLarger++;
    }
  }

  cout << "The average donation was " << avg << "\n";
  if (numLarger > 1) {
    cout << "There were " << numLarger << " donations "
	 << "that were above the average\n";
  }
  else {
    cout << "There was " << numLarger << " donation "
	 << "that was above the average\n";
  }

  delete [] donations;
  return 0;
}
