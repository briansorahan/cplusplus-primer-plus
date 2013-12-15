// capture keyboard input up to '#' and echo to a file called keyboard.capture
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

void exit_with_usage(void);

int main(int argc, char ** argv) {
    using namespace std;

    static const int LIMIT = 4096;
    char * from;
    char * to;
    // char ch[LIMIT];
    string str;

    if (argc < 3) {
        exit_with_usage();
    } else {
        from = argv[1];
        to = argv[2];
    }

    ifstream fin(from);
    ofstream fout(to);
    if (! fin.is_open()) {
        cerr << "Could not open " << from << endl;
        exit(EXIT_FAILURE);
    }
    if (! fout.is_open()) {
        cerr << "Could not open " << to << endl;
        exit(EXIT_FAILURE);
    }
    // while (fin.get(&ch[0], LIMIT)) {
    while (fin >> str) {
        fout << str;
    }
    fin.close();
    fout.close();
    return 0;
}

void exit_with_usage(void) {
    std::cerr << "Copy one file to another.\n"
              << "Usage: ./ex3 from to\n";
    exit(255);
}
