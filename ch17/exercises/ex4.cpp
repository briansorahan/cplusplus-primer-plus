// capture keyboard input up to '#' and echo to a file called keyboard.capture
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

void exit_with_usage(void);

int main(int argc, char ** argv) {
    using namespace std;

    if (argc < 4) {
        exit_with_usage();
    }

    static const int FILES = argc - 2;

    int i;
    int filesleft = FILES;
    bool done[FILES];
    ifstream * fins[FILES];
    ofstream fout(argv[1]);
    string str;

    for (i = 0; i < FILES; i++) {
        done[i] = false;
        fins[i] = new ifstream(argv[i + 2]);
    }

    while (filesleft > 0) {
        for (i = 0; i < FILES; i++) {
            if ((! done[i]) && (*fins[i] >> str)) {
                fout << str << ' ';
            } else {
                done[i] = true;
                filesleft--;
            }
        }
        if (filesleft > 0) {
            fout << endl;
        }
    }

    fout.close();

    for (i = 0; i < FILES; i++) {
        fins[i]->close();
        delete fins[i];
    }
    return 0;
}

void exit_with_usage(void) {
    std::cerr << "Concatenate the lines of two or more files.\n"
              << "Usage: ./ex4 output file1 file2 [file3...]\n";
    exit(255);
}
