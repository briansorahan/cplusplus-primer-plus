// binary file I/O
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

static const int LIM = 20;
static const char * file = "planets";

struct planet {
    char name[LIM];
    double population;
    double g;
};

static void showContents(std::fstream & finout, int * ct);
static void showRecord(long rec, const planet & pl);

inline void eatline() { while(std::cin.get() != '\n') continue; }

int main(int argc, char ** argv) {
    using namespace std;
    int ct;
    planet pl;
    cout << fixed;
    fstream finout(file, ios_base::in | ios_base::out | ios_base::binary);

    // show initial contents
    cout << "The current contents of " << file << " are:\n";
    showContents(finout, &ct);

    long rec;
    cout << "Enter the record number you wish to change: ";
    cin >> rec;
    eatline();
    if (rec < 0 || rec >= ct) {
        cerr << "Invalid record number\n";
        exit(EXIT_FAILURE);
    }

    streampos place = rec * (sizeof pl);
    finout.seekg(place);

    if (finout.fail()) {
        cerr << "Error seeking " << file << endl;
        exit(EXIT_FAILURE);
    }

    finout.read((char *) &pl, sizeof pl);
    cout << "Your selection:\n";
    showRecord(rec, pl);
    if (finout.eof()) {
        finout.clear();
    }

    cout << "Enter planet name (enter blank line to quit):\n";
    cin.get(pl.name, LIM);
    eatline();
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration due to gravity: ";
    cin >> pl.g;
    finout.seekp(place);
    finout.write((char *) &pl, sizeof pl) << flush;
    if (finout.fail()) {
        cerr << "Error writing to " << file << endl;
        exit(EXIT_FAILURE);
    }

    cout << "The new contents of " << file << " are:\n";
    showContents(finout, &ct);

    return 0;
}

static void showContents(std::fstream & finout, int * ct) {
    planet pl;
    *ct = 0;
    if (finout.is_open()) {
        finout.seekg(0);
        while (finout.read((char *) &pl, sizeof pl)) {
            std::cout << std::setw(4) << (*ct)++ << ": "
                      << std::setw(LIM) << pl.name << ' '
                      << std::setprecision(0) << std::setw(12) << pl.population
                      << std::setprecision(2) << std::setw(6) << pl.g << std::endl;
        }
        if (finout.eof()) {
            finout.clear();
        } else {
            std::cerr << "Error reading " << file << std::endl;
            exit(EXIT_FAILURE);
        }
    } else {
        std::cerr << "Could not open " << file << std::endl;
        exit(EXIT_FAILURE);
    }
}

static void showRecord(long rec, const planet & pl) {
    std::cout << std::setw(4) << rec << ": "
              << std::setw(LIM) << pl.name << ' '
              << std::setprecision(0) << std::setw(12) << pl.population
              << std::setprecision(2) << std::setw(6) << pl.g << std::endl;
}
