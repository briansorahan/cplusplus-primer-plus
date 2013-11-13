#include <iostream>
#include <string>
#include <vector>

const int NUM = 5;

int main(int argc, char ** argv) {
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<int> ratings(NUM);
    vector<string> titles(NUM);
    cout << "Please enter " << NUM << " book titles and your ratings [1-10].\n";

    int i;
    for (i = 0; i < NUM; i++) {
        cout << "Enter title #" << i + 1 << ": ";
        getline(cin, titles[i]);
        cout << "Enter your rating [1-10]: ";
        cin >> ratings[i];
        cin.get();
    }

    cout << "Thank you. You entered the following:\n"
         << "Rating\t\tBook\n";

    for (i = 0; i < NUM; i++) {
        cout << ratings[i] << "\t\t" << titles[i] << endl;
    }
}
