#include <iostream>
#include <cstring>

#include "queue.hpp"
#include "worker.hpp"

const int SIZE = 5;

template class Queue<Worker *>;

int main(int argc, char **argv) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Queue<Worker *> lolas(SIZE);

    int ct;
    Worker * w;
    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter    s: singer    "
             << "t: singing waiter    q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }

        if (choice == 'q') {
            break;
        }

        switch (choice) {
        case 'w':
            w = new Waiter;
            break;
        case 's':
            w = new Singer;
            break;
        case 't':
            w = new SingingWaiter;
            break;
        }

        cin.get();
        w->Set();
        lolas.enqueue(w);
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++) {
        lolas.dequeue(w);
        cout << endl;
        w->Show();
    }

    cout << "Bye.\n";

    delete w;
    return 0;
}
