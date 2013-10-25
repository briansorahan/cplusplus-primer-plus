// defining and using a Pair template

#include <iostream>
#include <string>
#include "pair.hpp"

int main(int argc, char **argv) {
    using std::cout;
    using std::endl;
    using std::string;

    Pair<string, int> ratings[4] = {
        Pair<string, int>("The Purpled Duck", 5),
        Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
        Pair<string, int>("Cafe Souffle", 5),
        Pair<string, int>("Bertie's Eats", 3)
    };

    int joints = sizeof(ratings) / sizeof(Pair<string, int>);
    cout << "Rating:\t Eatery\n";

    for (int i = 0; i < joints; i++) {
        cout << ratings[i].second() << ":\t "
             << ratings[i].first() << endl;
    }

    cout << "Oops! Revised rating:\n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;

    cout << ratings[3].second() << ":\t "
         << ratings[3].first() << endl;

    return 0;
}
