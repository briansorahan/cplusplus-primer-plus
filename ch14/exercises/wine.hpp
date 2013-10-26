#include <string>
#include <valarray>

#include "pair.hpp"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
typedef std::string WineLabel;

class Wine {
private:
    WineLabel name;
    int num_years;
    ArrayInt years;
    ArrayInt bottles;
public:
    Wine(const char * l, int y, const int yrs[], const int bots[]);
    Wine(const char * l, int y);
    Wine(std::string l, int y);
    ArrayInt getYears() const;
    ArrayInt getBottles() const;
    int getYear(const int i) const;
    int getBottle(const int i) const;
    void GetBottles();
    void Show() const;
    WineLabel Label() const;
    int sum() const;
    ~Wine() {}
};
