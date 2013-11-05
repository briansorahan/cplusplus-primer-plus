// returning an error code

#include <iostream>
#include <cfloat>

bool hmean(double a, double b, double * ans);

int main(int argc, char ** argv) {
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y) {
        if (hmean(x, y, &z)) {
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
        } else {
            cout << "One value should not be the negative of "
                 << "the other. Try again.\n";
        }

        cout << "Enter next set of numbers (q to quit): ";
    }
}

bool hmean(double a, double b, double * ans) {
    if (a == -b) {
        *ans = DBL_MAX;
        return false;
    } else {
        *ans = 2.0 * a * b / (a + b);
        return true;
    }
}
