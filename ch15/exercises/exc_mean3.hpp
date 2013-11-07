// exception classes for hmean, gmean

#ifndef EXC_MEAN3_HPP
#define EXC_MEAN3_HPP

#include <iostream>
#include <stdexcept>

using std::logic_error;

class mean_error : public logic_error {
private:
    double a;
    double b;
protected:
    const char * func_name;
public:
    mean_error(double x, double y, const char * msg, const char * fn)
        : logic_error(msg), a(x), b(y), func_name(fn) {}
    void callstr() const { std::cout << func_name << "(" << a << ", " << b << ")"; }
};

class bad_hmean : public mean_error {
public:
    bad_hmean(double x, double y, const char * msg)
        : mean_error(x, y, msg, "bad_hmean") {}
};

class bad_gmean : public mean_error {
public:
    bad_gmean(double x, double y, const char * msg)
        : mean_error(x, y, msg, "bad_gmean") {}
};

#endif
