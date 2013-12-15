// capture keyboard input up to '#' and echo to a file called keyboard.capture
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, const char ** const argv) {
    using namespace std;

    static const int LIMIT = 4096;
    static const char * file = "capture";

    char ch[LIMIT];
    ofstream fout(file);
    if (! fout.is_open()) {
        cerr << "Could not open " << file << endl;
        exit(EXIT_FAILURE);
    }
    while (cin.get(&ch[0], LIMIT, '#')) {
        fout << ch;
    }
    fout.close();
    return 0;
}
