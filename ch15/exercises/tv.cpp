// Tv and Remote implementation

#include "tv.hpp"

#include <iostream>

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    } else {
        return false;
    }
}

bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    } else {
        return false;
    }
}

void Tv::chanup() {
    if (channel < maxchannel) {
        channel++;
    } else {
        channel = 1;
    }
}

void Tv::chandown() {
    if (channel > 1) {
        channel--;
    } else {
        channel = maxchannel;
    }
}

void Tv::remote_mode(Remote & r) {
    if (state == On) {
        r.remoteMode = (r.remoteMode == Remote::NORMAL ? Remote::INTERACTIVE : Remote::NORMAL);
    }
}

void Tv::settings() const {
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On) {
        cout << "Volume setting = " << volume << endl
             << "Channel setting = " << channel << endl
             << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl
             << "Input = " << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Remote::display() const {
    using std::cout;
    using std::endl;

    cout << "TV Mode     = " << (mode == Tv::TV ? "TV" : "DVD") << endl;
    cout << "Remote Mode = " << (remoteMode == Remote::NORMAL ? "Normal" : "Interactive") << endl;
}
