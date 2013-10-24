// Exercise 6 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<limits.h>

// fills an array from user input
// terminates on non-numeric input
// returns the number of elements actually entered
int fill_array(double arr[], const int len);

// displays the contents of an array
void show_array(const double arr[], const int len);

// reverses an array in-place
void reverse_array(double arr[], const int len);

int main() {
  using namespace std;

  const int ARR_SIZE = 1000;
  double* arr = new double[ARR_SIZE];

  cout << "Please enter an array of double's:\n";
  int els_entered = fill_array(arr, ARR_SIZE);

  cout << "Here is the array you entered:\n";
  show_array(arr, els_entered);
  cout << endl;

  reverse_array(arr, els_entered);
  cout << "Here it is reversed:\n";
  show_array(arr, els_entered);
  cout << endl;

  // reverse everything but the first and
  // last elements
  cout << "Here it is with every element but the "
       << "first and last reversed:\n";
  reverse_array(arr + 1, els_entered - 2);
  show_array(arr, els_entered);
  cout << endl;

  delete [] arr;
  return 0;
}

int fill_array(double arr[], const int len) {
  using std::cin;

  int i = 0;
  while (i < len && cin >> arr[i]) {
    i++;
  }
  return i;
}

void show_array(const double arr[], const int len) {
  using namespace std;

  cout << "{";

  if (len > 0) {
    cout << arr[0];

    if (len > 1) {
      for (int i = 1; i < len; i++) {
	cout << ", " << arr[i];
      }
    }
  }

  cout << "}";
}

void reverse_array(double arr[], const int len) {
  if (len > 1) {
    for (int i = 0; i < len/2; i++) {
      double temp = arr[i];
      arr[i] = arr[len - 1 - i];
      arr[len - 1 - i] = temp;
    }
  }
}
