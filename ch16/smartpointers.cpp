// using three kinds of smart pointers
#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::cout;
using std::endl;

class Report {
private:
    string str;
public:
    Report(const string s) : str(s) {
        cout << "Object created!\n";
    }
    ~Report() {
        cout << "Object deleted!\n";
    }
    void comment() const {
        cout << str << endl;
    }
};

int main(int argc, char ** argv) {
    {
        std::auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment();
    }

    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment();
    }

    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
}
