// string2.hpp

#include <iostream>
using std::ostream;
using std::istream;

#ifndef __STRING2_H__
#define __STRING2_H__

class String {
private:
  char* str;                // pointer to string
  int len;                  // length of string
  static int num_strings;
  static const int CINLIM = 80; // cin input limit
public:
  String(const char* s);
  String(const String& sb); // copy constructor
  String();
  ~String();
  int length() const { return len; }
  void stringlow();
  void stringup();
  long has(char);
  // static (class) methods
  static int HowMany();
  // overloaded operators
  String& operator=(const String&);
  String& operator=(const char*);
  char& operator[](int i);
  const char& operator[](int i) const;
  // friends
  friend String operator+(const String&, const String&);
  friend bool operator<(const String &st1, const String& st2);
  friend bool operator>(const String &st1, const String& st2);
  friend bool operator==(const String &st1, const String& st2);
  friend istream& operator>>(istream& is, String& st);
  friend ostream& operator<<(ostream& os, const String& s);
};

#endif
