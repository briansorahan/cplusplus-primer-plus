// person.hpp -- Person interface.

#include <iostream>

class Person {
private:
  static const int LIMIT = 25;
  std::string lname;         // person's last name
  char fname[LIMIT];         // person's first name
public:
  Person() { lname = ""; fname[0] = '\0'; }
  Person(const std::string& ln, const char* fn = "Heyyou");
  void Show() const;         // displays <fname> <lname>
  void FormalShow() const;   // displays <lname, <fname>
};

