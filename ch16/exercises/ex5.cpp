#include <iostream>
#include <vector>
#include <algorithm>

// sorts ar, removes duplicates, then returns the number of
// elements in the result
template <typename T>
int reduce(T ar[], int n);
// would be nice to templatize the show* functions
void showLong(const long l);
void showString(const std::string s);

int main(int argc, char ** argv) {
    const int N = 8;

    long ar1[N] = { 2, 4, 8, 3, 4, 2, 1, 0 };
    int unique1 = reduce(ar1, N);

    std::cout << "ar1 = ";
    std::for_each(ar1, ar1 + N, showLong);
    std::cout << std::endl;
    std::cout << "Unique elements in ar1 = " << unique1 << std::endl;

    std::string ar2[N] = {
        "stanley",
        "stanley",
        "bo",
        "banley",
        "banana",
        "fana",
        "fo",
        "fanley"
    };
    int unique2 = reduce(ar2, N);

    std::cout << "ar2 = ";
    std::for_each(ar2, ar2 + N, showString);
    std::cout << std::endl;
    std::cout << "Unique elements in ar2 = " << unique2 << std::endl;

    return 0;
}

template <typename T>
int reduce(T ar[], int n) {
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

void showLong(const long l) {
    std::cout << l << ' ';
}

void showString(const std::string s) {
    std::cout << s << ' ';
}

