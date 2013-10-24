// golf.h -- Golf interface.

class Golf {
private:
  static const int LEN = 40;
  char fullname[LEN];
  int handicap;
public:
  Golf();
  Golf(const char* fn, int handicap);
  // Get the current handicap
  int getHandicap() const;
  // Set the handicap
  Golf setHandicap(int handicap);
  // Get the full name
  const char* getName() const;
  // Set the name
  Golf setName(const char* fullname);
  // Set all data for this golfer
  void setGolf(const char* fullname, int handicap);
  // Display this golfer's data on stdout
  void show() const;
};
