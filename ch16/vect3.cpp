// using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review {
    std::string title;
    int rating;
};

bool operator>(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main(int argc, char ** argv) {
    using namespace std;

    vector<Review> books;
    Review temp;

    while (FillReview(temp)) {
        books.push_back(temp);
    }

    if (books.size() > 0) {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
             << "Rating\t\tBook\n";

        // for_each(books.begin(), books.end(), ShowReview);
        for (Review b : books) ShowReview(b);

        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\t\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\t\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\t\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    } else {
        cout << "No entries\n";
    }

    return 0;
}

bool operator<(const Review & r1, const Review & r2) {
    return (r1.title < r2.title) || ((r1.title == r2.title) && (r2.rating < r2.rating));
}

bool worseThan(const Review & r1, const Review & r2) {
    return r1.rating < r2.rating;
}

bool FillReview(Review & rr) {
    using std::cout;
    using std::cin;
    using std::getline;

    cout << "Enter book title (quit to quit): ";
    getline(cin, rr.title);

    if (rr.title == "quit") {
        return false;
    }

    cout << "Enter book rating: ";
    cin >> rr.rating;

    if (! cin) {
        return false;
    }

    while (cin.get() != '\n') {
        continue;
    }

    return true;
}

void ShowReview(const Review & rr) {
    std::cout << rr.rating << "\t\t" << rr.title << std::endl;
}

