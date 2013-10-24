// tabletennis0.cpp -- TableTennis implementation

#include <string>
#include "tabletennis0.hpp"

TableTennisPlayer::TableTennisPlayer(const string& fn,
                                     const string& ln,
                                     bool ht)
    : firstname(fn), lastname(ln), hasTable(ht) {
    ;
}

std::string TableTennisPlayer::Name() const {
  return lastname + ", " + firstname;
}
