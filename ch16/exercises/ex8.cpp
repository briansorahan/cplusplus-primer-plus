// Mat and Pat
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

void Show(std::string s);

int main(int argc, char ** argv) {
    using namespace std;

    list<string> mat, pat;
    string temp;

    cout << "Enter Mat's friends (q to quit):\n";
    while ((cin >> temp) && temp != "q") {
        mat.push_back(temp);
    }
    mat.sort();
    cout << "Mat's friends: ";
    for_each(mat.begin(), mat.end(), Show);
    cout << endl;

    cout << "Enter Pat's friends (q to quit):\n";
    while ((cin >> temp) && temp != "q") {
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

    return 0;
}

void Show(std::string s) {
    std::cout << s << ' ';
}
