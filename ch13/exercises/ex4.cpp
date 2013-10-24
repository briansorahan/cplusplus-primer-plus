// Exercise 4 from Chapter 13 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include "port.hpp"

int main() {
    using namespace std;
    VintagePort cockburn = VintagePort("cockburn", 1, "cock", 1923);
    cout << cockburn << endl;
    return 0;
}
