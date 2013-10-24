#include <iostream>
#include "student.hpp"

using std::cin;
using std::cout;
using std::endl;

void set(Student& stu, int n);

const int pupils = 3;
const int quizzes = 5;

int main() {
    int i;
    Student ada[pupils] = {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };

    for (i = 0; i < pupils; i++) {
        set(ada[i], quizzes);
    }

    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; i++) {
        cout << ada[i].Name() << endl;
    }

    cout << "\nResults:";
    for (i = 0; i < pupils; i++) {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }

    cout << "Done.\n";
    return 0;
}

void set(Student& stu, int n) {
    cout << "Please enter the student's name: ";
    getline(cin, stu);

    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++) {
        cin >> stu[i];
    }

    while (cin.get() != '\n') {
        continue;
    }
}
