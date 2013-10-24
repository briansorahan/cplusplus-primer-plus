// Exercise 4 from Chapter 3 of C++ Primer

#include <iostream>

int main() {
  using namespace std;

  const int secs_per_min  = 60;
  const int min_per_hour = 60;
  const int hours_per_day  = 24;

  long long input_seconds;
  cout << "Enter the number of seconds: ";
  cin >> input_seconds;

  // Store the seconds that cannot be expressed
  // as a whole number of minutes
  long long seconds = input_seconds % secs_per_min;

  // Store the minutes that cannot be expressed
  // as a whole number of hours
  long long input_minutes = (input_seconds - seconds) / secs_per_min;
  long long minutes = input_minutes % min_per_hour;

  // Store the hours that cannot be expressed
  // as a whole number of days
  long long input_hours = (input_minutes - minutes) / min_per_hour;
  long long hours = input_hours % hours_per_day;

  // The number of days
  long long days = (input_hours - hours) / hours_per_day;

  cout << input_seconds << " seconds = "
       << days << " days, "
       << hours << " hours, "
       << minutes << " minutes, "
       << seconds << " seconds "
       << endl;

  return 0;
}
