// Exercise 3 from Chapter 9 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>

using namespace std;

const int BUF = 512;
char buffer[BUF];

struct chaff {
  char dross[20];
  int slag;
};

void showChaff(const chaff&);

int main() {
  const int NUM_CHAFFS = 2;

  // use placement new
  chaff* chaffs = new (buffer) chaff[NUM_CHAFFS];

  strcpy(chaffs[0].dross, "foo");
  chaffs[0].slag = 4;

  strcpy(chaffs[1].dross, "bar");
  chaffs[1].slag = 7;

  for (int i = 0; i < NUM_CHAFFS; i++) {
    showChaff( chaffs[i] );
  }

  return 0;
}

void showChaff(const chaff& c) {
  cout << "dross: " << c.dross << ", "
       << "slag:  " << c.slag << endl;
}
