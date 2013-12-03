// Lotto
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> Lotto(int totalSpots, int selectedSpots);

int main(int argc, char ** argv) {
    using std::cout;
    using std::endl;

    const int TOTAL_SPOTS = 51;
    const int SELECTED_SPOTS = 6;

    vector<int> winners = Lotto(TOTAL_SPOTS, SELECTED_SPOTS);
    cout << "The winners are: ";
    
    int i;
    for (i = 0; i < SELECTED_SPOTS; i++) {
        cout << winners[i] << ' ';
    }
    cout << endl;

    return 0;
}

vector<int> Lotto(int totalSpots, int selectedSpots) {
    vector<int> spots;

    int i;
    for (i = 0; i < totalSpots; i++) {
        spots.push_back(i);
    }

    random_shuffle(spots.begin(), spots.end());

    vector<int> selected;
    for (i = 0; i < selectedSpots; i++) {
        selected.push_back(spots[i]);
    }

    return selected;
}

