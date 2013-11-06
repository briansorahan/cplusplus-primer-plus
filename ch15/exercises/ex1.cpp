// using the TV and Remote classes

#include "tv.hpp"

#include <iostream>

int main(int argc, char **argv) {
    using std::cout;
    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();

    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();

    cout << "\nRemote settings before changing remote mode through 58\" tv:\n";
    grey.display();
    s58.remote_mode(grey);
    cout << "\nRemote settings after changing remote mode through 58\" tv:\n";
    grey.display();

    return 0;
}
