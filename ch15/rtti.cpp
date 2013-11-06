#include <cstdlib>
#include <ctime>

#include "rtti.hpp"

Grand * GetOne() {
    Grand * p;
    switch (std::rand() % 3) {
    case 0:
        p = new Grand(std::rand() % 100);
        break;
    case 1:
        p = new Superb(std::rand() % 100);
        break;
    case 2:
        p = new Magnificent(std::rand() % 100,
                            'A' + (std::rand() % 26));
        break;
    }
    return p;
}
