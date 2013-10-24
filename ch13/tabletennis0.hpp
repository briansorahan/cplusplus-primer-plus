// tabletennis0.hpp -- a table-tennis base class
// version 0

#ifndef __TABLETENNIS0_H__
#define __TABLETENNIS0_H__

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
    string Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};

#endif
