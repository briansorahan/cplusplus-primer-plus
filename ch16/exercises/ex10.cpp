// using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using std::shared_ptr;

struct Review {
    std::string title;
    int rating;
    double price;
};

bool operator>(const shared_ptr< Review > r1, const shared_ptr< Review > r2);
bool worseThan(const shared_ptr< Review > r1, const shared_ptr< Review > r2);
bool cheaperThan(const shared_ptr< Review > r1, const shared_ptr< Review > r2);
bool FillReview(shared_ptr< Review > & rr);
void ShowReview(const shared_ptr< Review > & rr);

int main(int argc, char ** argv) {
    using namespace std;

    vector< shared_ptr< Review > > books;
    shared_ptr< Review > temp;

    while (FillReview(temp)) {
        books.push_back(temp);
    }

    if (books.size() > 0) {
        string choice;
        cout << "Enter display ordering (t=title, r=review, pi=price(increasing) pd=price(decreasing), q to quit): ";
        while((cin >> choice) && (choice != "q")) {
            if (choice == "t") {
                sort(books.begin(), books.end());
                cout << "Sorted by title:\nRating\t\tBook\t\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
            } else if (choice == "r") {
                sort(books.begin(), books.end(), worseThan);
                cout << "Sorted by rating:\nRating\t\tBook\t\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
            } else if (choice == "pi") {
                sort(books.begin(), books.end(), cheaperThan);
                cout << "Sorted by price:\nRating\t\tBook\t\tPrice\n";
                for_each(books.begin(), books.end(), ShowReview);
            } else if (choice == "pd") {
                sort(books.begin(), books.end(), cheaperThan);
                cout << "Sorted by price:\nRating\t\tBook\t\tPrice\n";
                for_each(books.rbegin(), books.rend(), ShowReview);
            } else {
                cout << "Invalid choice: " << choice << endl;
            }

            cout << "Enter display ordering (t=title, r=review, pi=price(increasing) pd=price(decreasing), q to quit): ";
        }
    } else {
        cout << "No entries\n";
    }

    return 0;
}

bool operator<(const shared_ptr< Review > r1, const shared_ptr< Review > r2) {
    return (r1->title < r2->title) || ((r1->title == r2->title) && (r2->rating < r2->rating));
}

bool worseThan(const shared_ptr< Review > r1, const shared_ptr< Review > r2) {
    return r1->rating < r2->rating;
}

bool cheaperThan(const shared_ptr< Review > r1, const shared_ptr< Review > r2) {
    return r1->price < r2->price;
}

bool FillReview(shared_ptr< Review > & rr) {
    using std::cout;
    using std::cin;
    using std::getline;

    rr = shared_ptr< Review >(new Review);

    cout << "Enter book title (q to quit): ";
    getline(cin, rr->title);

    if (rr->title == "q") {
        return false;
    }

    cout << "Enter book rating: ";
    cin >> rr->rating;

    if (! cin) {
        return false;
    }

    cout << "Enter book price: ";
    cin >> rr->price;

    if (! cin) {
        return false;
    }

    while (cin.get() != '\n') {
        continue;
    }

    return true;
}

void ShowReview(const shared_ptr< Review > & rr) {
    std::cout << rr->rating
              << "\t\t" << rr->title
              << "\t\t" << rr->price << std::endl;
}

