#include "worker.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Data() const {
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get() {
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n') {
        continue;
    }
}

void Waiter::Set() {
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const { 
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const {
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get() {
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n') {
        continue;
    }
}

Waiter & Waiter::operator=(const Waiter & w) {
    if (this == &w) return *this;

    fullname = w.fullname;
    id = w.id;
    panache = w.panache;

    return *this;
}

std::string Singer::pv[Singer::Vtypes] = {
    "other",
    "alto",
    "contralto",
    "soprano",
    "bass",
    "baritone",
    "tenor"
};

void Singer::Set() {
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const {
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}

void Singer::Data() const {
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get() {
    cout << "Enter number for singer's vocal range: ";
    int i;
    for (i = 0; i < Vtypes; i++) {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3) {
            cout << endl;
        }
    }

    if (i % 4 != 0) {
        cout << endl;
    }

    cin >> voice;
    while (cin.get() != '\n') {
        continue;
    }
}

Singer & Singer::operator=(const Singer & s) {
    if (this == &s) return *this;

    voice = s.voice;

    return *this;
}

void SingingWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get() {
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set() {
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const {
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}

SingingWaiter & SingingWaiter::operator=(const SingingWaiter & s) {
    if (this == &s) return *this;

    Waiter::operator=(s);
    Singer::operator=(s);

    return *this;
}

