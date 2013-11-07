// read strings from a file
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char ** argv) {
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");
    if (fin.is_open() == false) {
        cerr << "Can't open file tobuy.txt\n";
        exit(EXIT_FAILURE);
    }
    string item;
    int count = 0;
    getline(fin, item);
    while (fin) {
        cout << ++count << ": " << item << endl;
        getline(fin, item);
    }
    cout << "Done\n";
    fin.close();
    return 0;
}
