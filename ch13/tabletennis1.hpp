// tabletennis1.hpp -- a table-tennis base class
// version 1

#ifndef __TABLETENNIS1_H__
#define __TABLETENNIS1_H__

#include <string>
using std::string;

// base class
class TableTennisPlayer {
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string& fn = "-",
                      const string& ln = "-",
                      bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};

// derived class
class RatedPlayer : public TableTennisPlayer {
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const string& fn = "-",
                const string& ln = "-", bool hasTable = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer& tp);
    unsigned int Rating() const { return rating; }
    void ResetRating(unsigned int r = 0) { rating = r; }
};

#endif
