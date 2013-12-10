// writing to a file
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char ** argv) {
    using namespace std;
    string filename;
    float secret;
    cout << "Enter name for new file: ";
    cin >> filename;
    ofstream fout(filename.c_str());
    fout << "For your eyes only!\n";
    cout << "Enter your secret number: ";
    cin >> secret;
    fout << "Your secret number is " << secret << endl;
    fout.close();
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << ":\n";
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    cout << "Done\n";
    fin.close();
    return 0;
}
