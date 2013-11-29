// hangman game using string methods

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;
using std::vector;

const int NUM = 26;
vector<string> wordlist;

bool readwords(vector<string> & ws, const string filename);

int main(int argc, char ** argv) {
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;

    std::srand(std::time(0));

    // read word list
    vector<string> ws;
    const string filename = "words";
    bool succeeded = readwords(ws, filename);
    const int NUM = ws.size();

    // play the game
    char play;
    cout << "Will you play a word game? (y or n) ";
    cin >> play;
    play = tolower(play);

    while (play == 'y') {
        string target = ws[std::rand() % NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;

        cout << "Guess my secret word. It has " << length
             << " letters, and you guess one letter at a time.\n"
             << " You get " << guesses << " guesses\n";

        cout <<  "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target) {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos) {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);
            if (loc == string::npos) {
                cout << "Bad guess.\n";
                guesses--;
                badchars += letter;
            } else {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while (loc != string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;
            if (attempt != target) {
                if (badchars.length() > 0) {
                    cout << "Bad choices: " << badchars << endl;
                }

                cout << guesses << " bad guesses left.\n";
            }
        }

        if (guesses > 0) {
            cout << "That's right!\n";
        } else {
            cout << "Sorry, the word is " << target << ".\n";
        }

        cout << "Will you  play another? (y or n) ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye!\n";
    return 0;
}

bool readwords(vector<string> & ws, const string filename) {
    std::ifstream infile(filename);
    string w;

    while (std::getline(infile, w)) {
        ws.push_back(w);
    }

    return true;
}
