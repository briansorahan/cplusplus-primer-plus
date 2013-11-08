// stock02.cpp -- augemented version
// version 02

#include <iostream>
#include "stock02.hpp"

// default constructor
Stock::Stock() {
  std::cout << "Default constructor called.\n";
  company = "none";
  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr) {
  std::cout << "Constructor using " << co << " called.\n";
  company = co;
  if (n < 0) {
    std::cout << "Number of shares can't be negative. "
	      << company << " shares set to 0.\n";
    shares = 0;
  }
  else {
    shares = n;
  }

  share_val = pr;
  set_tot();
}

Stock::~Stock() {
  std::cout << "Bye, " << company << "!\n";
}

void Stock::buy(long num, double price) {
  if (num < 0) {
    std::cout << "Number of shares purchased can not be negative. "
	      << "Transaction aborted.\n";
  }
  else {
    shares += num;
    share_val = price;
    set_tot();
  }
}

void Stock::sell(long num, double price) {
  using std::cout;

  if (num < 0) {
    cout << "Number of shares sold can not be negative. "
	 << "Transaction aborted.\n";
  }
  else if (num > shares) {
    cout << "You can not sell more than you have! "
	 << "Transaction aborted.\n";
  }
  else {
    shares -= num;
    share_val = price;
    set_tot();
  }
}

void Stock::update(double price) {
  share_val = price;
  set_tot();
}

void Stock::show() const {
  using std::cout;
  using std::endl;
  using std::ios_base;

  // set format to #.###
  ios_base::fmtflags orig =
    cout.setf(ios_base::fixed, ios_base::floatfield);
  std::streamsize prec = cout.precision(3);

  cout << "Company: " << company << endl
       << "  Shares:      " << shares << endl;

  cout.precision(2);
  cout << "  Share Price: $" << share_val << endl
       << "  Total Worth: $" << total_val << endl;

  // restore original format
  cout.setf(orig, ios_base::floatfield);
  cout.precision(prec);
}

const Stock& Stock::topval(const Stock& s) const {
  if (s.total_val > total_val) {
    return s;
  }
  else {
    return *this;
  }
}
