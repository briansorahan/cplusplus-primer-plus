// Exercise 2 from Chapter 7 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<array>

// Number of golf scores
const int Scores = 10;
// Fetch golf scores from user input
void getScores(std::array<double, Scores> * psc);
// Get the average of some golf scores
double averageScore(const std::array<double, Scores> * psc);
// Display the scores
void displayScores(const std::array<double, Scores> * psc);

int main() {
  std::array<double, Scores> scores;
  getScores(&scores);
  displayScores(&scores);
  return 0;
}

void getScores(std::array<double, Scores> * psc) {
  std::cout << "Please enter the golf scores:\n"
	    << "(any non-numeric input quits)\n";

  int i = 0;
  double score;
  while (i < Scores && std::cin >> score) {
    (*psc)[i++] = score;
  }
}

double averageScore(const std::array<double, Scores> * psc) {
  double total;
  for (int i = 0; i < Scores; i++) {
    total += (*psc)[i];
  }
  return total / Scores;
}

void displayScores(const std::array<double, Scores> * psc) {
  std::cout << "Scores were: ";
  for (int i = 0; i < Scores; i++) {
    std::cout << (*psc)[i] << " ";
  }

  std::cout << std::endl
	    << "Average = " << averageScore(psc)
	    << std::endl;
}
