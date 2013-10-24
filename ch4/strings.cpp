// strings.cpp -- storing strings in an array

#include <iostream>
#include <cstring>

int main() {
  using namespace std;

  const int size = 15;
  char name1[size];
  char name2[size] = "C++owboy";

  cout << "Howdy! I'm " << name2 << "." << endl;
  cout << "What's your name?" << endl;
  cin >> name1;

  cout << "Well, " << name1 << ", your name has "
       << strlen(name1) << " letters and is stored" << endl
       << "in an array of " << sizeof name1 << " bytes." << endl;

  cout << "Your first initial is " << name1[0] << "." << endl;

  name2[3] = '\0';
  cout << "Here are the first three characters of my name: "
       << name2 << endl;

  return 0;
}
