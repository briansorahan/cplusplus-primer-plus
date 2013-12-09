// using format manipulators
#include <iostream>

int main(int argc, char ** argv) {
    using namespace std;

    cout << "Enter an integer: ";
    int n;
    cin >> n;

    cout << "n        n*n\n";
    cout << n << "        " << n*n << "  (decimal)\n";
    // set to hex mode
    cout << hex;
    cout << n << "        " << n*n << "  (hexadecimal)\n";
    // set to octal
    cout << oct << n << "        " << n*n << "  (octal)\n";
    // alternative way to call a manipulator
    dec(cout);
    cout << n << "        " << n*n << "  (decimal)\n";

    return 0;
}
