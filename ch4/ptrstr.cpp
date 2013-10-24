// ptrstr.cpp -- using pointers to strings

#include <iostream>
#include <cstring>

int main() {
  using namespace std;

  char animal[20] = "bear";
  const char* bird = "wren";
  char* ps;

  cout << animal << " and "
       << bird << endl;
  // cout << ps << endl; // may display garbage, may cause a crash

  cout << "Enter a kind of animal: ";
  cin >> animal; // ok if input < 20 chars
  // cin >> ps;  // Too horrible a blunder to try.
  //             // ps doesn't point to allocated space.

  ps = animal;
  cout << ps << "!" << endl;
  cout << "Before using strcpy():" << endl;
  cout << animal << " at " << (int*) animal << endl;
  cout << ps << " at " << (int*) ps << endl;

  ps = new char[strlen(animal) + 1];
  strcpy(ps, animal);

  cout << "After using strcpy():" << endl;
  cout << animal << " at " << (int*) animal << endl;
  cout << ps << " at " << (int*) ps << endl;

  delete [] ps;

  return 0;
}
