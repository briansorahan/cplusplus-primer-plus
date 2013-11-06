// using dynamic_cast, typeid, and type_info
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

#include "rtti.hpp"

using namespace std;

int main(int argc, char ** argv) {
    srand(time(0));
    Grand * pg;
    Superb * ps;
    for (int i = 0; i < 5; i++) {
        pg = GetOne();
        cout << "Now processing type " << typeid(*pg).name() << ".\n";
        pg->Speak();
        if (ps = dynamic_cast<Superb *>(pg)) {
            ps->Say();
        }

        if (typeid(Magnificent) == typeid(*pg)) {
            cout << "Yes, you're really magnificent!\n";
        }
    }

    return 0;
}
