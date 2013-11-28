// Palindromes (ignoring capitalization)

#include <iostream>
#include <string>

bool ispalindrome(const std::string & s);

int main(int argc, char ** argv) {
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
}

bool ispalindrome(const std::string & s) {
    bool result = true;
    const int sz = s.size();
    for (int i = 0; i < sz; i++) {
        result = result && (s[i] == s[sz - i - 1]);
    }
    return result;
}
