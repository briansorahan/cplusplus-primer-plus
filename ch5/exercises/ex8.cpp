// Exercise 8 from Chapter 5 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>

int main() {
  using namespace std;

  const int MAX_WORD_SIZE = 80;
  char* word = new char[MAX_WORD_SIZE];
  int numWords = 0;

  // cin.get(word, MAX_WORD_SIZE).get();
  cin >> word;
  // cout << "first word = " << word << endl;
  while (strcmp(word, "done") != 0) {
    numWords++;
    // cin.get(word, MAX_WORD_SIZE).get();
    cin >> word;
    // cout << "word = " << word << endl;
  }
  
  cout << "You entered " << numWords << " words."
       << endl;
  
  delete [] word;
  return 0;
}
