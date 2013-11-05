// using exception classes

#include <iostream>
#include <cmath>

#include "exc_mean.hpp"

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
        } catch (bad_hmean & bh) {
            bh.mesg();
            cout << "Try again.\n";
        } catch (bad_gmean & bg) {
            cout << bg.mesg();
            cout << "Try again.\n";
        }

        cout << "Enter next set of numbers (q to quit): ";
    }

    return 0;
}

double hmean(double a, double b) {
    if (a == -b) {
        throw bad_hmean(a, b);
    } else {
        return (2.0 * a * b) / (a + b);
    }
}

double gmean(double a, double b) {
    if (a < 0 || b < 0) {
        throw bad_gmean(a, b);
    } else {
        return std::sqrt(a * b);
    }
}
