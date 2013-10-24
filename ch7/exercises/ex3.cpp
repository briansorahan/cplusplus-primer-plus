// Exercise 3 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

struct box {
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
};

// Display info about a box
void showBox(box b);
// Set the volume
void setVolume(box* b);

int main() {
  box b = {
    "Brian",  // maker
    3,        // height
    4,        // width
    5,        // length
    0         // volume (obviously wrong)
  };

  showBox(b);
  return 0;
}

void showBox(box b) {
  using namespace std;
  
  setVolume(&b); // Ensure the volume is set correctly

  cout << "Info about the box made by " << b.maker << ":\n";
  cout << "  height: " << b.height << endl;
  cout << "   width: " << b.width << endl;
  cout << "  length: " << b.length << endl;
  cout << "  volume: " << b.volume << endl;
}

void setVolume(box* b) {
  b->volume = b->height * b->width * b->length;
}
