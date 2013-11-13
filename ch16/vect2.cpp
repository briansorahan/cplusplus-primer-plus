// methods and iterators
#include <iostream>
#include <string>
#include <vector>

struct Review {
    std::string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main(int argc, char ** argv) {
    using std::cout;
    using std::vector;

    vector<Review> books;
    Review temp;

    while (FillReview(temp)) {
        books.push_back(temp);
    }

    int num = books.size();
    if (num > 0) {
        cout << "Thank you. You entered the following:\n"
             << "Rating\t\tBook\n";
        for (int i = 0;  i < num; i++) {
            ShowReview(books[i]);
        }
        cout << "Reprising:\n"
             << "Rating\t\tBook\n";
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++) {
            ShowReview(*pr);
        }
        vector<Review> oldlist(books);

        if (num > 3) {
            // remove 2 items
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasing:\n";
            for (pr = books.begin(); pr != books.end(); pr++) {
                ShowReview(*pr);
            }

            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++) {
                ShowReview(*pr);
            }
        }

        cout << "Swapping oldlist with books:\n";
        books.swap(oldlist);
        for (pr = books.begin(); pr != books.end(); pr++) {
            ShowReview(*pr);
        }
    } else {
        cout << "Nothing entered, nothing gained.\n";
    }

    return 0;
}

bool FillReview(Review & rr) {
    using std::cout;
    using std::getline;
    using std::cin;

    cout << "Enter book title (quit to quit): ";
    getline(cin, rr.title);
    if (rr.title == "quit") {
        return false;
    }
    cout << "Enter book rating: ";
    cin >> rr.rating;
    if (!std::cin) {
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
