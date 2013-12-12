// formatted reading from a char array
#include <iostream>
#include <sstream>
#include <string>

int  main(int argc, char ** argv) {
    using namespace std;
    string lit = "It was a dark and stormy day, and "
        "the moon glowed brilliantly.";
    istringstream instr(lit); // use buf for input
    string word;
    while (instr >> word) {
        cout << word << endl;
    }
    return 0;
}
