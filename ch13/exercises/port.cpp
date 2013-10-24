#include <iostream>
#include <cstring>
#include "port.hpp"

using namespace std;

static const int STR_LEN = 80;

// ===================
// Port implementation
// ===================

Port::Port(const char* br, const char* st, int b)
    : bottles(b) {
    brand = new char[STR_LEN];
    std::strcpy(brand, br);
    std::strcpy(style, st);
}

Port::Port(const Port& p) { // copy constructor
    brand = new char[STR_LEN];
    bottles = p.bottles;
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
}

Port& Port::operator=(const Port& p) {
    if (this == &p)
        return *this;

    delete [] brand;
    delete [] style;

    brand = new char[STR_LEN];
    bottles = p.bottles;
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);

    return *this;
}

Port& Port::operator+=(int b) { // add b to bottles
    bottles += b;
    return *this;
}

Port& Port::operator-=(int b) { // subtract
    if (b > bottles) {
        bottles = 0;
    } else {
        bottles -= b;
    }
}

void Port::Show() const {
    using std::endl;
    std::cout << "Brand: " << brand << endl
              << "Kind: " << style << endl
              << "Bottles: " << bottles << endl;
}

ostream& operator<<(ostream& os, const Port& p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

// ==========================
// VintagePort implementation
// ==========================

VintagePort::VintagePort() : Port("none", "vintage", 0) {
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
    : Port(br, "vintage", b) {
    nickname = new char[STR_LEN];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp) {
    nickname = new char[STR_LEN];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp) {
    if (this == &vp) {
        return *this;
    }

    Port::operator=(vp);

    delete [] nickname;
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}
