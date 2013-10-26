#include <iostream>
#include <string>
#include <valarray>

#include "wine.hpp"

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using std::valarray;

    string lab;
    int yrs;

    cout << "Enter name of wine: ";
    getline(cin, lab);

    cout << "Enter number of years: ";
    cin >> yrs;

    Wine collection(lab, yrs);
    collection.GetBottles();
    collection.Show();

    const int YRS = 3;
    int y[YRS] = { 1993, 1995, 1998 };
    int b[YRS] = { 48,   60,   72   };
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label()
         << ": " << more.sum() << endl;
    cout << "Bye.\n";

    return 0;
}
