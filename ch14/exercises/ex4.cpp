#include <iostream>
#include <string>
#include <cstring>

#include "queue.hpp"
#include "person.hpp"

const int SIZE = 10;

int main(int argc, char **argv) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Queue<Person *> outlaws(SIZE);

    int ct;

    // gunslinger fields
    int notches;
    double drawtime;

    char choice;
    string firstname, lastname;
    Person * p;

    for (ct = 0; ct < SIZE; ct++) {
        cout << "Enter the first name: ";
        getline(cin, firstname);
        cout << "Enter the last name: ";
        getline(cin, lastname);

        p = new Person(firstname, lastname);

        cout << "Enter the person category:\n"
             << "g: gunslinger    p: poker player    "
             << "b: bad dude    q: quit\n";
        cin >> choice;
        while (strchr("gpbq", choice) == NULL) {
            cout << "Please enter g, p, b, or q: ";
            cin >> choice;
        }

        if (choice == 'q') {
            break;
        }

        switch (choice) {
        case 'g':
            cout << "Enter draw time: ";
            cin >> drawtime;
            cout << "Enter number of notches on the gunslinger's gun: ";
            cin >> notches;

            p = new Gunslinger(*p, drawtime, notches);
            break;
        case 'p':
            p = new PokerPlayer(*p);
            break;
        case 'b':
            cout << "Enter draw time: ";
            cin >> drawtime;
            cout << "Enter number of notches on the gunslinger's gun: ";
            cin >> notches;

            p = new BadDude(*p, drawtime, notches);
            break;
        }

        cin.get();
        outlaws.enqueue(p);
    }

    cout << "\nHere are the outlaws:\n";
    int i;
    for (i = 0; i < ct; i++) {
        outlaws.dequeue(p);
        cout << endl;
        p->Show();
    }

    cout << "\nBye.\n";

    // delete p;
    return 0;
}
