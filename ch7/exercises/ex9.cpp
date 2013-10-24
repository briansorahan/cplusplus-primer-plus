// Exercise 9 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<cstring>

using namespace std;

const int SLEN = 40;

struct student {
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

// getinfo() has two arguments:
// 1 - a pointer to the first element of an array
//     of student structures
// 2 - an int representing the number of elements
//     of the array.
// It solicits and stores data about students.
// It terminates input upon filling the array or
// upon encountering a blank line for the
// student name.
// It returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);

// display1() takes a student structure as an
// argument and displays its contents
void display1(student s);

// display2() takes the address of a student
// structure as an argument and displays
// the structure's contents
void display2(const student* ps);

// display3() takes the address of the first element
// of an array of student structures and the
// number of array elements as arguments and displays
// the contents of the structures
void display3(const student pa[], int n);

int main() {
  int class_size;
  cout << "Enter class size: ";
  cin >> class_size;

  while (cin.get() != '\n') {
    continue;
  }

  student* ps = new student[class_size];
  int entered = getinfo(ps, class_size);

  for (int i = 0; i < entered; i++) {
    display1(ps[i]);
    display2(&ps[i]);
  }

  display3(ps, entered);

  delete [] ps;

  cout << "Done.\n";
  return 0;
}

int getinfo(student ps[], int class_size) {
  for (int i = 0; i < class_size; i++) {
    student* s = new student;
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;

    cout << "For student #" << (i+1) << ":\n";
    cout << "Enter full name: ";
    cin.get(s->fullname, SLEN).get();

    // Exit the loop if the name was blank
    if (strcmp(s->fullname, "") == 0) {
      break;
    }

    cout << "Enter hobby: ";
    cin.get(s->hobby, SLEN).get();

    cout << "Enter oop level: ";
    cin >> s->ooplevel;
    cin.get();

    ps[i] = *s;
    delete s;
  }
}

void display1(student s) {
  cout << endl << s.fullname << endl;
  cout << "  hobby:    " << s.hobby << endl;
  cout << "  ooplevel: " << s.ooplevel << endl;
}

void display2(const student* ps) {
  display1(*ps);
}

void display3(const student pa[], int n) {
  for (int i = 0; i < n; i++) {
    display1(pa[i]);
  }
}
