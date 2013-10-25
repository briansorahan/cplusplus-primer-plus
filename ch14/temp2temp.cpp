// template friends to a template class

#include <iostream>

using std::cout;
using std::endl;

// template prototypes
template <typename T> void counts();
template <typename T> void report(T &);

// template class
template <typename U>
class HasFriend {
private:
    U item;
    static int ct;
public:
    HasFriend(const U & u) : item(u) { ct++; }
    ~HasFriend() { ct--; }
    friend void counts<U>();
    friend void report<>(HasFriend<U> &);
};

template <typename T>
int HasFriend<T>::ct = 0;

// template friend function definitions
template <typename T>
void counts() {
    cout << "template size: " << sizeof(HasFriend<T>) << "; "
         << "template counts(): " << HasFriend<T>::ct << endl;
}

template <typename T>
void report(T & hf) {
    cout << hf.item << endl;
}

int main() {
    counts<int>();
    
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    HasFriend<double> hfd1(10.5);

    report(hfi1);
    report(hfi2);
    report(hfd1);

    cout << "counts<int>() output:\n";
    counts<int>();

    cout << "counts<double>() output:\n";
    counts<double>();

    return 0;
}
