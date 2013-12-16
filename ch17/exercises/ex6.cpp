// counitng characters in a list of files
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "employee.hpp"

static const char * filename(void) {
    static const char * f = "ex6.dat";
    return f;
}

int main(int argc, char ** argv) {
    using namespace std;

    if (argc == 1) {
        cerr << "Usage: " << argv[0] << " filename(s)\n";
        exit(EXIT_FAILURE);
    }

    ifstream fin(filename());
    ofstream fout(filename());
    long count;
    long total = 0;
    char ch;

    for (int file = 1; file < argc; file++) {
        fin.open(argv[file]);
        if (! fin.is_open()) {
            cerr << "Could not open " << argv[file] << endl;
            fin.clear();
            continue;
        }

        count = 0;
        while (fin.get(ch)) {
            count++;
        }

        cout << count << " characters in " << argv[file] << endl;
        total += count;
        fin.clear();
        fin.close();
    }

    cout << total << " characters in all files\n";

    return 0;
}
