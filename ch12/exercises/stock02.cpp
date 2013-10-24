// stock02.cpp -- augemented version
// version 02

#include <iostream>
#include <cstring>
#include "stock02.hpp"

using std::ostream;

// default constructor
Stock::Stock() {
  std::cout << "Default constructor called.\n";
  len = 0;
  company = new char[len + 1];
  company[len] = '\0';
  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr) {
  std::cout << "Constructor using " << co << " called.\n";

  len = std::strlen(co);
  company = new char[len + 1];
  std::strcpy(company, co);

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
  delete [] company;
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

const Stock& Stock::topval(const Stock& s) const {
  if (s.total_val > total_val) {
    return s;
  }
  else {
    return *this;
  }
}

ostream& operator<<(ostream& os, const Stock& stock) {
  using std::endl;
  using std::ios_base;

  // set format to #.###
  ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
  std::streamsize prec = os.precision(3);

  os << "Company: " << stock.company << endl
     << "  Shares:      " << stock.shares << endl;

  os.precision(2);
  os << "  Share Price: $" << stock.share_val << endl
     << "  Total Worth: $" << stock.total_val << endl;

  // restore original format
  os.setf(orig, ios_base::floatfield);
  os.precision(prec);
}

Stock& Stock::operator=(const Stock& st) {
  if (this == &st) return *this;
  delete [] company;
  len = st.len;
  company = new char[len + 1];
  std::strcpy(company, st.company);
  shares = st.shares;
  share_val = st.share_val;
  total_val = st.total_val;
  return *this;
}
