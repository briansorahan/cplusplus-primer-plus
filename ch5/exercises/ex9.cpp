// Exercise 9 from Chapter 5 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>
#include<string>

int main() {
  using namespace std;

  // const int MAX_WORD_SIZE = 80;
  // char* word = new char[MAX_WORD_SIZE];
  string word;
  int numWords = 0;

  cin >> word;
  while (word != "done") {
    numWords++;
    cin >> word;
  }
  
  cout << "You entered " << numWords << " words."
       << endl;
  
  // delete word;
  return 0;
}
