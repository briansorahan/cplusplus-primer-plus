#include <iostream>
#include <vector>
#include <algorithm>

// sorts ar, removes duplicates, then returns the number of
// elements in the result
int reduce(long ar[], int n);

void showLong(long l);

int main(int argc, char ** argv) {
    const int N = 8;

    long ar1[N] = { 2, 4, 8, 3, 4, 2, 1, 0 };
    int unique1 = reduce(ar1, N);

    std::cout << "ar1 = ";
    std::for_each(ar1, ar1 + N, showLong);
    std::cout << std::endl;
    std::cout << "Unique elements in ar1 = " << unique1 << std::endl;

    long ar2[N] = { 6, 5, 8, 3, 4, 2, 1, 0 };
    int unique2 = reduce(ar2, N);

    std::cout << "ar2 = ";
    std::for_each(ar2, ar2 + N, showLong);
    std::cout << std::endl;
    std::cout << "Unique elements in ar2 = " << unique2 << std::endl;

    return 0;
}

int reduce(long ar[], int n) {
    std::sort(ar, ar + n);
    int unique = 1; // first element is always unique
    int i = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && (ar[i] != ar[i - 1])) {
            ++unique;
        }
    }

    return unique;
}

void showLong(long l) {
    std::cout << l << ' ';
}
