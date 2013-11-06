// exception classes for hmean, gmean

#include <iostream>
#include <stdexcept>

using std::logic_error;

class bad_hmean : public logic_error {
public:
    bad_hmean(const char * msg) : logic_error(msg) {}
};

class bad_gmean : public logic_error {
public:
    bad_gmean(const char * msg) : logic_error(msg) {}
};
