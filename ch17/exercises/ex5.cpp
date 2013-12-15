// Mat and Pat
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

void Show(std::string s);

int main(int argc, char ** argv) {
    using namespace std;

    ifstream matin("mat.dat");
    ifstream patin("pat.dat");
    ofstream fout("matnpat.dat");
    list<string> mat, pat;
    string temp;

    while (getline(matin, temp)) {
        mat.push_back(temp);
    }
    mat.sort();
    cout << "Mat's friends: ";
    for_each(mat.begin(), mat.end(), Show);
    cout << endl;

    while (getline(patin, temp)) {
        pat.push_back(temp);
    }
    pat.sort();
    cout << "Pat's friends: ";
    for_each(pat.begin(), pat.end(), Show);
    cout << endl;

    list<string> merged(mat);
    merged.merge(pat);
    cout << "Mat and Pat's friends merged: ";
    merged.unique();
    for_each(merged.begin(), merged.end(), Show);
    cout << endl;

    matin.close();
    patin.close();
    fout.close();
    return 0;
}

void Show(std::string s) {
    std::cout << s << ' ';
}
