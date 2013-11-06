// using the dynamic_cast operator
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "rtti.hpp"

using std::cout;

int main(int argc, char ** argv) {
    std::srand(std::time(0));
    Grand * pg;
    Superb * ps;
    for (int i = 0; i < 5; i++) {
        pg = GetOne();
        pg->Speak();
        if (ps = dynamic_cast<Superb *>(pg)) {
            ps->Say();
        }
    }
    return 0;
}

