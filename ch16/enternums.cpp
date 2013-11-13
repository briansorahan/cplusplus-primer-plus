#include <iostream>
#include <vector>

int main(int argc, char ** argv) {
    using std::vector;
    using std::cout;
    using std::cin;

    double temp;
    vector<double> scores;
    while (cin >> temp && temp >= 0) {
        scores.push_back(temp);
    }
    cout << "You entered " << scores.size() << " scores.\n";
}
