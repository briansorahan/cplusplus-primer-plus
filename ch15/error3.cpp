// using exceptions and try/catch

#include <iostream>

double hmean(double a, double b);

int main(int argc, char ** argv) {
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y) {
        try {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
        } catch (const char * s) {
            cout << s << endl;
        }

        cout << "Enter next set of numbers (q to quit): ";
    }
}

double hmean(double a, double b) {
    if (a == -b) {
        throw "hmean() cannot be called with two numbers whose sum is zero";
    } else {
        return 2.0 * a * b / (a + b);
    }
}

