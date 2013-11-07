// using exception classes

#include <iostream>
#include <cmath>

#include "exc_mean3.hpp"

double hmean(double a, double b);
double gmean(double a, double b);

int main(int argc, char ** argv) {
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            z = gmean(x, y);
            cout << "Geometric mean of " << x << " and " << y << " is " << z << endl;
        } catch (mean_error & me) {
            me.callstr();
            cout << ": " << me.what() << endl;
        }

        cout << "Enter next set of numbers (q to quit): ";
    }

    return 0;
}

double hmean(double a, double b) {
    if (a == -b) {
        throw bad_hmean(a, b, "arguments can not sum to 0");
    } else {
        return (2.0 * a * b) / (a + b);
    }
}

double gmean(double a, double b) {
    if (a < 0 || b < 0) {
        throw bad_gmean(a, b, "arguments should be >= 0");
    } else {
        return std::sqrt(a * b);
    }
}
