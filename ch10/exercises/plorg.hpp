// Plorg interface definition
// Brian Sorahan

#ifndef PLORG_H_
#define PLORG_H_

class Plorg {
private:
  static const int LEN = 19;  // max name length
  char name[LEN];      // name
  int ci;              // contentment index
public:
  Plorg();
  Plorg(const char*, int);
  // set contentment index
  void setCI(int);
  void show() const;
};

#endif
