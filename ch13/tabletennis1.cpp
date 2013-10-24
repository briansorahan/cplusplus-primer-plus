// tabletennis1.cpp -- TableTennis implementation

#include <iostream>
#include "tabletennis1.hpp"

TableTennisPlayer::TableTennisPlayer(const string& fn,
                                     const string& ln,
                                     bool ht)
    : firstname(fn), lastname(ln), hasTable(ht) {
}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string& fn,
                         const string& ln, bool hasTable)
    : TableTennisPlayer(fn, ln, hasTable), rating(r) {
    // rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& ttp)
    : TableTennisPlayer(ttp), rating(r) {
}
