// usett0.cpp -- using a base class

#include <iostream>
#include "tabletennis0.hpp"

int main() {
    using std::cout;
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", true);

    if (player1.HasTable()) {
        cout << player1.Name() << ": has a table.\n";
    } else {
        cout << player1.Name() << ": doesn't have a table.\n";
    }

    if (player2.HasTable()) {
        cout << player2.Name() << ": has a table.\n";
    } else {
        cout << player2.Name() << ": doesn't have a table.\n";
    }

    return 0;
}
