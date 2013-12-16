// header file for abstr_emp class and children

#ifndef EMP_HPP
#define EMP_HPP

#include <iostream>
#include <string>

using std::string;

class abstr_emp {
private:
    string fname;
    string lname;
    string job;
public:
    abstr_emp();
    abstr_emp(const string & fn, const string & ln, const string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    // displays first and last name
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp {
public:
    employee();
    employee(const string & fn, const string ln, const string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager : virtual public employee {
private:
    int inchargeof;
protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }
public:
    manager();
    manager(const string & fn, const string & ln, const string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink : virtual public abstr_emp {
private:
    string reportsto;
protected:
    const string ReportsTo() const { return reportsto; }
    string & ReportsTo() { return reportsto; }
public:
    fink();
    fink(const string & fn, const string & ln, const string & j, const string & rpo);
    fink(const abstr_emp & e, const string & rpo);
    fink(const fink & f);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink : public manager, public fink {
public:
    highfink();
    highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico);
    highfink(const abstr_emp & e, const string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
};

// =========
// abstr_emp
// =========

abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j)
    : fname(fn), lname(ln), job(j) {}

// ========
// employee
// ========

employee::employee(const string & fn, const string ln, const string & j)
    : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const {
}

void employee::SetAll() {
}

// =======
// manager
// =======

manager::manager() {}

manager::manager(const string & fn, const string & ln, const string & j, int ico) {}

manager::manager(const abstr_emp & e, int ico) {}

manager::manager(const manager & m) {}

void manager::ShowAll() const {}

void manager::SetAll() {}

// ====
// fink
// ====

fink::fink() {}
fink::fink(const string & fn, const string & ln, const string & j, const string & rpo) {}

fink::fink(const abstr_emp & e, const string & rpo) {}

fink::fink(const fink & f) {}

void fink::ShowAll() const {}

void fink::SetAll() {}

// ========
// highfink
// ========

highfink::highfink() {}

highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico) {}

highfink::highfink(const abstr_emp & e, const string & rpo, int ico) {}

highfink::highfink(const fink & f, int ico) {}

highfink::highfink(const manager & m, const string & rpo) {}

highfink::highfink(const highfink & h) {}

void highfink::ShowAll() const {}

void highfink::SetAll() {}

#endif
