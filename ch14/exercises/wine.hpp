#include <string>
#include <valarray>

#include "pair.hpp"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
private:
    string name;
    int num_years;
    PairArray coll;
public:
    Wine(const char * l, int y, const int yrs[], const int bots[]);
    Wine(const char * l, int y);
    ~Wine() {}
};
