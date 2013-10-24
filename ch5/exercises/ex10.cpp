// Exercise 10 from Chapter 5 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

int main() {
  using namespace std;
  int rows = 0;

  cout << "Enter number of rows: ";
  cin >> rows;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      if (j < rows - 1 - i) {
	cout << '.';
      }
      else {
	cout << '*';
      }
    }
    
    cout << endl;
  }

  return 0;
}
