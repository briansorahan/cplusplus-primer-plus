// Exercise 7 from Chapter 6 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>
#include<cctype>

bool isvowel(char c);

int main() {
  using namespace std;

  const int MAX_LENGTH = 80;

  char word[MAX_LENGTH];
  int beginWithVowel = 0;
  int beginWithConsonant = 0;
  int neither = 0;

  cout << "Enter words (q to quit):" << endl;

  while(cin >> word && strcmp(word, "q")) {
    if (isvowel(word[0])) {
      beginWithVowel++;
    }
    else if (isalpha(word[0])) {
      // must be a consonant if it is alpha but not vowel
      beginWithConsonant++;
    }
    else {
      neither++;
    }
  }

  cout << "Words that begin with a vowel: " << beginWithVowel << endl
       << "Words that begin with a consonant: " << beginWithConsonant << endl
       << "Other: " << neither << endl
       << endl;

  return 0;
}

bool isvowel(char c) {
  return 
    c == 'a' ||
    c == 'e' ||
    c == 'i' ||
    c == 'o' ||
    c == 'u';
}
