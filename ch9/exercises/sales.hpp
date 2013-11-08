// SALES namespace

namespace sales {
  const int QUARTERS = 4;
  struct Sales {
    double sales[QUARTERS];
    double average;
    double max;
    double min;
  };

  // copies the lesser of 4 or n items from the
  // array to the sales member of s and computes
  // and stores the average, max, and min values
  // of the entered items
  // remaining elements of sales, if any, are
  // set to 0
  void setSales(Sales& s, const double arr[], int n = QUARTERS);

  // gathers sales for 4 quarters interactively,
  // stores them in the sales member of s and
  // computes and stores the average, max, and
  // min values
  void setSales(Sales& s);

  // display all information for this Sales object
  void showSales(const Sales& s, int n = QUARTERS);
}
