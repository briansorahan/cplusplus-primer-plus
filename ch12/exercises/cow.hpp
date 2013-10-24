// cow.hpp -- Cow interface

class Cow {
private:
  char name[20];
  char* hobby;
  double weight;
public:
  Cow();
  Cow(const char* nm, const char* hob, double wt);
  Cow(const Cow& c);
  ~Cow();
  Cow& operator=(const Cow& c);
  void ShowCow() const; // display cow's data on stdout
};
