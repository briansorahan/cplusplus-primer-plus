#include <string>
#include <valarray>

#include "pair.hpp"

Wine::Wine(const char * l, int y, const int yrs[], const int bots[]) 
    : name(l),
      num_years(y) {
    
}

Wine::Wine(const char * l, int y) {
}

Wine::~Wine() {
}
