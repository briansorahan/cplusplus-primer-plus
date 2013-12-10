// having cin throw an exception
#include <iostream>
#include <exception>

int main(int argc, char ** argv) {
    using namespace std;
    // have failbit cause an exception to be thrown
    cin.exceptions(ios_base::failbit);
    cout << "Enter numbers: ";
    int sum = 0;
    int input;
    try {
        while (cin >> input) {
            sum += input;
        }
    } catch (ios_base::failure & failure) {
        cout << failure.what() << endl;
        cout << "O! The horror!\n";
    }

    cout << "Last value entered: " << input << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}
