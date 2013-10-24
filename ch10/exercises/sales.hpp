// SALES namespace

namespace sales {
  const int QUARTERS = 4;
  class Sales {
  private:
    double sales[QUARTERS];
    double average;
    double max;
    double min;
  public:
    Sales();
    Sales(const double sales[], int n = QUARTERS);
    // copies the lesser of QUARTERS or n items from the
    // array to the sales member of s and computes
    // and stores the average, max, and min values
    // of the entered items
    // remaining elements of sales, if any, are
    // set to 0
    void setSales(const double sales[], int n = QUARTERS);
    // interactive version
    void setSales();
    // display all information for this Sales object
    void showSales(int n = QUARTERS) const;
  };
}
