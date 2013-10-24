// utf8.cpp -- UTF-8 string literals

#include <iostream>
#include <string>

int main() {
  using namespace std;
  string s = u8"hi";
  cout << s << endl;
  return 0;
}
