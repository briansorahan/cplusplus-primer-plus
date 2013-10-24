// twofile1.cpp -- variables with external and internal linkage
#include<iostream>
int tom = 3;   // external variable definition
int dick = 30; // external variable definition
static int harry = 300; // static, internal linkage

void remote_access();

int main() {
  using namespace std;
  cout << "main() reports the following addresses:\n";
  cout << &tom << " = &tom, " << &dick << " = &dick, "
       << &harry << " = &harry\n";
  remote_access();
  return 0;
}
