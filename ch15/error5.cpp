// unwinding the stack

#include <iostream>
#include <cmath>
#include <string>

#include "exc_mean.hpp"

class demo {
private:
    std::string word;
public:
    demo(const std::string & str) {
        word = str;
        std::cout << "demo " << word << " created\n";
    }
    ~demo() {
        std::cout << "demo " << word << " destroyed\n";
    }
    void show() {
        std::cout << "demo " << word << " lives!\n";
    }
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main(int argc, char ** argv) {
    using std::cout;
    using std::endl;
    using std::cin;

    double x, y, z;

    {
        demo d1("found in block in main");
        cout << "Enter two numbers: ";
        while (cin >> x >> y) {
            try {
                z = means(x, y);
                cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
            } catch (bad_hmean & bh) {
                bh.mesg();
                cout << "Try again.\n";
            } catch (bad_gmean & bg) {
                cout << bg.mesg();
                cout << "Try again.\n";
            }

            cout << "Enter next set of numbers (q to quit): ";
        }

        d1.show();
    }

    cin.get();
    cin.get();

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

double means(double a, double b) {
    double am, hm, gm;
    demo d2("found in means()");
    am = (a + b) / 2.0;

    hm = hmean(a, b);
    gm = gmean(a, b);

    d2.show();
    return (am + hm + gm) / 3.0;
}
