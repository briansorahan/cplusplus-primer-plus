#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#ifndef PERSON_HPP
#define PERSON_HPP

using std::string;

typedef struct _Card {
    string suit;
    int value;
} Card;

typedef enum {
    Spades,
    Clubs,
    Diamonds,
    Hearts
} Suit;

const string SUIT_STRINGS[4] = {
    "Spades",
    "Hearts",
    "Diamonds",
    "Clubs"
};

class Person {
private:
    std::string firstname;
    std::string lastname;
public:
    Person()
        : firstname("John"), lastname("Doe") {
    }

    Person(string f, string l)
        : firstname(f), lastname(l) {
    }

    Person(const Person & p) {
        firstname = p.firstname;
        lastname = p.lastname;
    }

    virtual void Show() const;
    // virtual double Draw() const = 0;
};

class Gunslinger : virtual public Person {
private:
    double drawtime;
    int notches;
public:
    Gunslinger()
        : Person(), drawtime(10), notches(4) {
    }

    Gunslinger(double dt, int n)
        : Person(), drawtime(dt), notches(n) {
    }

    Gunslinger(string fn, string ln)
        : Person(fn, ln), drawtime(10), notches(4) {
    }

    Gunslinger(string fn, string ln, double dt, int n)
        : Person(fn, ln), drawtime(dt), notches(n) {
    }

    Gunslinger(const Person & p)
        : Person(p), drawtime(10), notches(4) {}

    Gunslinger(const Person & p, double dt, int n)
        : Person(p), drawtime(dt), notches(n) {}

    double Draw() const { return drawtime; }
    void Show() const;
};

class PokerPlayer : virtual public Person {
public:
    PokerPlayer() {
        srand(time(0));
    }

    PokerPlayer(const Person & p)
        : Person(p) {}

    Card Draw() const;
    void Show() const;
};

class BadDude : public Gunslinger, PokerPlayer {
public:
    BadDude()
        : Gunslinger(), PokerPlayer() {}

    BadDude(double dt, int n)
        : Gunslinger(dt, n), PokerPlayer() {}

    BadDude(const Person & p)
        : Person(p), Gunslinger() {
    }

    BadDude(const Person & p, double dt, int n)
        : Person(p), Gunslinger(dt, n) {
    }

    double GDraw() const;
    Card CDraw() const;
    void Show() const;
};

void Person::Show() const {
    std::cout << lastname << ", " << firstname;
}

void Gunslinger::Show() const {
    Person::Show();
    std::cout << "    -- draw time: " << drawtime << ", notches: " << notches;
}

Card PokerPlayer::Draw() const {
    Suit suit = (Suit) (rand() % 4);
    int value = (rand() % 13) + 1;
    return { SUIT_STRINGS[suit], value };
}

void PokerPlayer::Show() const {
    Person::Show();
}

double BadDude::GDraw() const {
    return Gunslinger::Draw();
}

Card BadDude::CDraw() const {
    return PokerPlayer::Draw();
}

void BadDude::Show() const {
    Gunslinger::Show();
}

#endif
