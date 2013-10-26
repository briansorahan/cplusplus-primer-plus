#include <iostream>
#include <string>
#include <valarray>

#include "wine.hpp"

Wine::Wine(const char * l, int y, const int yrs[], const int bots[]) 
    : name(l), num_years(y), years(y), bottles(y) {
    for (int i = 0; i < y; i++) {
        years[i] = yrs[i];
        bottles[i] = bots[i];
    }
}

Wine::Wine(const char * l, int y)
    : name(l), num_years(y), years(y), bottles(y) {
}

Wine::Wine(std::string l, int y)
    : name(l), num_years(y), years(y), bottles(y) {
}

ArrayInt Wine::getYears() const {
    return years;
}

ArrayInt Wine::getBottles() const {
    return bottles;
}

int Wine::getYear(const int i) const {
    if (0 < i && i < num_years) {
        return years[i];
    } else {
        return 0;
    }
}

int Wine::getBottle(const int i) const {
    if (0 < i && i < num_years) {
        return bottles[i];
    } else {
        return 0;
    }
}

void Wine::GetBottles() {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter " << name << " data for " << num_years << " year(s)\n";
    for (int i = 0; i < num_years; i++) {
        cout << "Enter year: ";
        cin >> years[i];
        cout << "Enter bottles for that year: ";
        cin >> bottles[i];
    }
}

void Wine::Show() const {
    using std::cout;
    using std::endl;

    cout << "Wine: " << name << endl;
    cout << "\tYear\tBottles\n";
    for (int i = 0; i < num_years; i++) {
        cout << "\t" << years[i] << "\t" << bottles[i] << endl;
    }
}

WineLabel Wine::Label() const {
    return name;
}

int Wine::sum() const {
    return bottles.sum();
}
