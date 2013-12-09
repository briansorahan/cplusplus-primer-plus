// using the width method
#include <iostream>

int main(int argc, char ** argv) {
    using std::cout;
    int w = cout.width(10);
    cout << "default field width = " << w << ":\n";
    cout.width(5);
    cout << "N" << ":";
    cout.width(8);
    cout << "N * N" << ":\n";

    for (long i = 1; i <= 100; i *= 10) {
        cout.width(5);
        cout << i << ":";
        cout.width(8);
        cout << i * i << ":\n";
    }

    return 0;
}
