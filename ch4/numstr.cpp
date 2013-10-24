// numstr.cpp -- following number input with line input

#include <iostream>

int main() {
  using namespace std;

  cout << "What year was your house built?" << endl;
  int year;
  cin >> year;
  cin.get(); // discard the newline

  cout << "What is the street address?" << endl;
  const int line_length = 80;
  char address[line_length];
  cin.getline(address, line_length);

  cout << "Year built: " << year << endl;
  cout << "Address: " << address << endl;
  cout << "Done!" << endl;

  return 0;
}
