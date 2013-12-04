#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <vector>
#include <algorithm>

int main(int argc, char ** argv) {
    using namespace std;

    clock_t start, end;

    // seed prng
    srand(time(0));

    // number of elements in the lists
    const int N = 1000000;

    vector<int> vi0;

    int i;
    for (i = 0; i < N; i++) {
        vi0.push_back(rand());
    }

    vector<int> vi(N);
    list<int> li(N);

    // copy over the elements from vi0
    for (i = 0; i < N; i++) {
        vi[i] = vi0[i];
    }
    li.insert(li.begin(), vi0.begin(), vi0.end());

    // time vector sort
    start = clock();
    sort(vi.begin(), vi.end());
    end = clock();
    cout << "sort vector time = "
         << (end - start) << endl;

    // time list sort
    start = clock();
    li.sort();
    end = clock();
    cout << "sort list time   = "
         << (end - start) << endl;

    return 0;
}
