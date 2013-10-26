#ifndef WORKER_HPP
#define WORKER_HPP

#include <string>

class Worker {
protected:
    virtual void Data() const;
    virtual void Get();
// private:
    std::string fullname;
    long id;
public:
    Worker() : fullname("nobody"), id(0L) {}
    Worker(const std::string & s, long n) : fullname(s), id(n) {}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
    // virtual Worker & operator=(const Worker & w) = 0;
};

class Waiter : virtual public Worker {
protected:
    void Data() const;
    void Get();
private:
    int panache;
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waiter(const Worker & wk, int p = 0)
        : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
    Waiter & operator=(const Waiter & w);
};

class Singer : virtual public Worker {
protected:
    enum {
        other,
        alto,
        contralto,
        soprano,
        bass,
        baritone,
        tenor
    };
    enum { Vtypes = 7 };
    void Data() const;
    void Get();
private:
    static std::string pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other)
        : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other)
        : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
    Singer & operator=(const Singer & s);
};

class SingingWaiter : public Singer, public Waiter {
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker & wk, int p = 0, int v = other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter & wt, int v = other)
        : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer & s, int p = 0)
        : Worker(s), Waiter(s, p), Singer(s) {}
    void Set();
    void Show() const;
    SingingWaiter & operator=(const SingingWaiter & s);
};

#endif
