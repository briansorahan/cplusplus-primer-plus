// string2.cpp -- String implementation

#include <cstring>
#include <cctype>
#include "string2.hpp"

using std::cout;
using std::istream;
using std::ostream;

////////////////////////////////////////////////////////////////////////////////
// class methods
////////////////////////////////////////////////////////////////////////////////

int String::num_strings = 0;

int String::HowMany() {
  return num_strings;
}

////////////////////////////////////////////////////////////////////////////////
// instance methods
////////////////////////////////////////////////////////////////////////////////

// construct String from C string
String::String(const char* s) {
  len = std::strlen(s);              // set size
  str = new char[len + 1];           // allocate storage
  std::strcpy(str, s);               // initialize pointer
  num_strings++;
}

String::String() {
  len = 0;
  str = new char[len + 1];
  str[len] = '\0';
  num_strings++;
}

// copy constructor
String::String(const String& st) {
  num_strings++;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
  num_strings++;
}

// destructor is necessary
String::~String() {
  --num_strings;
  delete [] str;
}

void String::stringlow() {
  int i;
  for (i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }
}

void String::stringup() {
  int i;
  for (i = 0; i < len; i++) {
    str[i] = toupper(str[i]);
  }
}

long String::has(char c) {
  long n = 0;
  int i;
  for (i = 0; i < len; i++) {
    if (str[i] == c) n++;
  }
  return n;
}


////////////////////////////////////////////////////////////////////////////////
// overloaded operators
////////////////////////////////////////////////////////////////////////////////

// assignment operator
String& String::operator=(const String& st) {
  if (this == &st)
    return *this;
  delete [] str;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
  return *this;
}

// avoids creating a temporary object with the
// String& constructor and then copying it to
// another String object when you assign a C string
String& String::operator=(const char* s) {
  delete [] str;
  len = std::strlen(s);
  str = new char[len + 1];
  std::strcpy(str, s);
  return *this;
}


char& String::operator[](int i) {
  return str[i];
}

const char& String::operator[](int i) const {
  return str[i];
}

////////////////////////////////////////////////////////////////////////////////
// friends
////////////////////////////////////////////////////////////////////////////////

String operator+(const String& st1, const String& st2) {
  int totalLen = st1.len + st2.len;
  char* combined = new char[totalLen + 1];
  std::strcpy(combined, st1.str);
  std::strcat(combined, st2.str);
  return String(combined);
}

bool operator<(const String &st1, const String& st2) {
  return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String& st2) {
  return st2 < st1;
}

bool operator==(const String &st1, const String& st2) {
  return (std::strcmp(st1.str, st2.str) == 0);
}

istream& operator>>(istream& is, String& st) {
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);

  if (is) {
    st = temp;
  }

  while (is && is.get() != '\n') {
    continue;
  }

  return is;
}

ostream& operator<<(ostream& os, const String& s) {
  os << s.str;
  return os;
}

