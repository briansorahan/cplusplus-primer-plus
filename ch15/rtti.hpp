#ifndef RTTI_HPP
#define RTTI_HPP

#include <iostream>

using std::cout;

class Grand {
private:
    int hold;
public:
    Grand(int h = 0) : hold(h) {}
    virtual void Speak() const { cout << "I am a grand class!\n"; }
    virtual int Value() const { return hold; }
};

class Superb : public Grand {
public:
    Superb(int h = 0) : Grand(h) {}
    void Speak() const { cout << "I am a superb class!\n"; }
    virtual void Say() const {
        cout << "I hold the superb value of " << Value() << "!\n";
    }
};

class Magnificent : public Superb {
private:
    char ch;
public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
    void Speak() const { cout << "I am a magnificent class!\n"; }
    void Say() const {
        cout << "I hold the character " << ch
             << " and the integer " << Value() << "!\n";
    }
};

Grand * GetOne();

#endif
