#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

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

const string SUITS[4] = {
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
        : firstname("John"), lastname("doe") {
    }

    Person(string f, string l)
        : firstname(f), lastname(l) {
    }

    void Show() const;
};

class Gunslinger : virtual public Person {
private:
    double drawtime;
    int notches;
public:
    Gunslinger()
        : drawtime(10), notches(4) {
    }

    Gunslinger(double dt, int n)
        : drawtime(dt), notches(n) {
    }

    double Draw() const { return drawtime; }
    void Show() const;
};

class PokerPlayer : virtual public Person {
public:
    Card Draw() const;
};

class BadDude : Gunslinger, PokerPlayer {
};

#endif
