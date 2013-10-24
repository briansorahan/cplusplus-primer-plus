#include<iostream>
#include<cstring>

using namespace std;

// Compute the maximum of an array of T's
template <typename T> T maxn(T[], int n);
template <> const char* maxn(const char*[], int n);

int main() {
  int ints[4] = { 1, 2, 3, 4 };
  cout << "max of ints is " << maxn(ints, 4) << endl;
  const char* abcs[] = {"a", "bee", "c"};
  cout << "longest word is " << maxn(abcs, 3) << endl;
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
template <> const char* maxn(const char* ca[], int n) {
  const char* longest = ca[0];
  int len = strlen(ca[0]);
  for (int i = 1; i < n; i++) {
    int l = strlen(ca[i]);
    if (l > len) {
      longest = ca[i];
      len = l;
    }
  }
  return longest;
}
