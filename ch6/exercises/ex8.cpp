// Exercise 8 from Chapter 6 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<string>
#include<fstream>

int main() {
  using namespace std;

  string filename = "ex1.cpp";
  ifstream filein;
  
  filein.open(filename);

  char c;
  int numChars = 0;
  while ((filein.get(c)) && c != EOF) {
    numChars++;
  }

  cout << "Number of characters in " << filename
       << ": " << numChars << "." << endl;

  filein.close();
  return 0;
}
