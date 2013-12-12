// count the characters in an input stream up to the first '$'
#include <iostream>

static const int LIMIT = 4096;

int main(int argc, char ** argv) {
    using namespace std;

    char c;
    long count = 0;
    while (cin.get(c) && c != '$') {
        count++;
    }

    cout << "characters: " << count << endl;

    return 0;
}
