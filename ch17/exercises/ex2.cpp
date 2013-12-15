// capture keyboard input up to '#' and echo to a file called keyboard.capture
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

void exit_with_usage(void);

int main(int argc, char ** argv) {
    using namespace std;

    static const int LIMIT = 4096;
    char * filename;
    char ch[LIMIT];

    if (argc < 2) {
        exit_with_usage();
    } else {
        filename = argv[1];
    }

    ofstream fout(filename);
    if (! fout.is_open()) {
        cerr << "Could not open " << filename << endl;
        exit(EXIT_FAILURE);
    }
    while (cin.get(&ch[0], LIMIT, '#')) {
        fout << ch;
    }
    fout.close();
    return 0;
}

void exit_with_usage(void) {
    std::cerr << "Usage: ./ex2 filename\n";
    exit(255);
}
