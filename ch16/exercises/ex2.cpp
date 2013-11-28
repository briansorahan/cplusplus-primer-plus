// Palindromes (with capitalization)

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using std::string;

bool ispalindrome(const string & s);
string canonicalize(const string s);

int main(int argc, char ** argv) {
    using std::cout;
    using std::endl;

    bool racecar = ispalindrome("racecar");
    if (racecar) {
        std::cout << "racecar is a palindrome\n";
    } else {
        std::cout << "racecar is not a palindrome\n";
    }

    bool foo = ispalindrome("foo");
    if (foo) {
        std::cout << "foo is a palindrome\n";
    } else {
        std::cout << "foo is not a palindrome\n";
    }

    bool madam = ispalindrome("Madam, I'm Adam");
    if (madam) {
        cout << "madam is a palindrome\n";
    } else {
        cout << "madam is not a palindrome\n";
    }
}

bool ispalindrome(const string & s) {
    bool result = true;
    string str = canonicalize(s);
    const int sz = strlen(str.c_str());
    for (int i = 0; i < sz; i++) {
        result = result && (str[i] == str[sz - i - 1]);
    }
    return result;
}

string canonicalize(const string s) {
    const int sz = s.size();
    string result(sz, '\0');

    int j = 0;
    for (int i = 0; i < sz; i++) {
        if (isalnum(s[i])) {
            result[j++] = tolower(s[i]);
        }
    }

    return result;
}
