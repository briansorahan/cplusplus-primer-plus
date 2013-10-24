// Exercise 6 from Chapter 8 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>

using namespace std;

// Compute the maximum of 5 T's
template <typename T> T maxn(T[], int n);
template <> char* maxn(char*[], int n);

int main() {
  const int ARR_SIZE1 = 4;
  const int ARR_SIZE2 = 6;

  int ints[ARR_SIZE1] = { 1, 2, 3, 4 };
  double doubles[ARR_SIZE2] = { -1.2, -3.4, -5.6, -7.8, -9.0, 48.0 };

  cout << "max of ints is " << maxn(ints, ARR_SIZE1) << endl;
  cout << "max of doubles is " << maxn(doubles, ARR_SIZE2) << endl;
  
  const char* palindrome[] = {
    "Able", "was", "I", "ere", "I", "saw", "Elba"
  };

  const char* longestWord = maxn(palindrome, 7);
  cout << "longest word of palindrome is " << longestWord << endl;

  return 0;
}

// Compute the maximum of an array of T's
template <typename T> T maxn(T arr[], int n) {
  T max = arr[0];
  for (int i = 1; i < n; i++) {
    T t = arr[i];
    if (t > max) max = t;
  }
  return max;
}

// Compute the longest word
template <> char* maxn(char* ca[], int n) {
  char* longest = ca[0];
  int len = strlen(ca[0]);
  for (int i = 1; i < n; i++) {
    cout << ca[i] << endl;
    int l = strlen(ca[i]);
    if (l > len) {
      cout << "Found a longer one." << endl;
      longest = ca[i];
      len = l;
    }
  }
  return longest;
}
