// TV and Remote classes

#ifndef TV_HPP
#define TV_HPP

class TV {
public:
    friend class Remote;
    enum { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };

    TV(int s, Off, int mc = 125)
        : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() { state = (state == On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void set_input() { input = (input == TV) ? DVD : TV; }
    void settings() const;
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

class Remote {
private:
    int mode;
public:
    Remote(int m = TV::TV) : mode(m) {}
    bool volup(TV & t) { return t.volup(); }
    bool voldown(TV & t) { return t.voldown(); }
    void onoff(TV & t) { t.onoff(); }
    void chanup(TV & t) { t.chanup(); }
    void chandown(TV & t) { t.chandown(); }
    void set_chan(TV & t, int c) { t.channel = c; }
    void set_mode(TV & t) { t.set_mode(); }
    void set_input(TV & t) { t.set_input(); }
};

#endif
