// using setf() to control formatting
#include <iostream>

int main(int argc, char ** argv) {
    using std::cout;
    using std::endl;
    using std::ios_base;

    int temperature = 6;
    cout << "Today's water temperature: ";
    cout.setf(ios_base::showpos);
    cout << temperature << endl;

    cout << "For our programming friends, that's\n";
    cout << std::hex << temperature << endl;
    cout.setf(ios_base::uppercase);
    cout.setf(ios_base::showbase);
    cout << "or\n";
    cout << temperature << endl;
    cout << "How " << true << "! oops -- How ";
    cout.setf(ios_base::boolalpha);
    cout << true << "!\n";
    return 0;
}
