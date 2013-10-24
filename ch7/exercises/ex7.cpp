// Exercise 7 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>

// fills an array from user input
// terminates on non-numeric input
// returns the number of elements actually entered
int fill_array(double* first, double* end);

// displays the contents of an array
void show_array(double* first, double* end);

// reverses an array in-place
void reverse_array(double* first, double* end);

int main() {
  using namespace std;

  const int ARR_SIZE = 100;
  double* arr = new double[ARR_SIZE];

  cout << "Please enter an array of double's:\n";
  int els_entered = fill_array(arr, arr + ARR_SIZE);

  // cout << "You entered " << els_entered << " elements.\n";
  cout << "Here is the array you entered:\n";
  show_array(arr, arr + els_entered);
  cout << endl;

  reverse_array(arr, arr + els_entered);
  cout << "Here it is reversed:\n";
  show_array(arr, arr + els_entered);
  cout << endl;

  // reverse everything but the first and
  // last elements
  cout << "Here it is with every element but the "
       << "first and last reversed:\n";
  reverse_array(arr + 1, arr + els_entered - 1);
  show_array(arr, arr + els_entered);
  cout << endl;

  delete [] arr;
  return 0;
}

int fill_array(double* first, double* end) {
  using std::cin;

  int i = 0;
  double in;
  for (double* pt = first; pt != end; pt++) {
    cin >> in;
    
    if (cin) {
      *pt = in;
      i++;
    }
    else {
      break;
    }
  }

  return i;
}

void show_array(double* first, double* end) {
  using namespace std;

  cout << "{";

  if (first != end) {
    cout << *first;

    if (first + 1 != end) {
      for (double* pt = first + 1; pt != end; pt++) {
  	cout << ", " << *pt;
      }
    }
  }

  cout << "}";
}

void reverse_array(double* first, double* end) {
  int len = end - first;

  if (first + 1 != end) {
    for (int i = 0; i < len/2; i++) {
      double temp = *(first + i);
      *(first + i) = *(end - 1 - i);
      *(end - 1 - i) = temp;
    }
  }
}
