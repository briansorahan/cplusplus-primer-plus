// Exercise 6 from Chapter 6 of C++ Primer Plus
// Brian Sorahan

#include<iostream>
#include<string>

// Show the main menu
void showmenu();

using namespace std;

struct contributor {
  string name;
  double contribution;
};

// Arbitrary max for the contributor array
const int MAX_CONTRIBUTORS = 1000;
// Add a contributor to an array of contributors
void addContributor(contributor* cs, int i);
// Display a list of contributors
void showContributors(contributor* cs, int max);

int main() {
  contributor* cs = new contributor[MAX_CONTRIBUTORS];

  showmenu();
  char choice;
  int numContributors = 0;
  
  cin >> choice;
  while (choice != 'q') {
    switch (choice) {
    case 'c':
      addContributor(cs, numContributors);
      numContributors++;

      cout << "Thank you!\n\n";
      break;
    }

    showmenu();
    cin >> choice;
  }

  showContributors(cs, numContributors);

  delete [] cs;
  return 0;
}

void showmenu() {
  cout << "Please select an option:\n";
  cout << "c) Enter a contributor\n";
  cout << "q) Quit\n";
}

void addContributor(contributor* cs, int i) {
  contributor* c = new contributor;

  cout << "  Name: ";
  cin >> c->name;
      
  cout << "  Contribution: ";
  cin >> c->contribution;
  cin.get();

  cs[i] = *c;
  delete c;
}

void showContributors(contributor* cs, int numContributors) {
  int grandPatrons = 0;
  int numRemaining = 0;
  contributor* remaining = new contributor[MAX_CONTRIBUTORS];

  cout << "Grand Patrons:" << endl;
  if (numContributors == 0) {
    cout << "  none" << endl;
  }
  else {
    for (int i = 0; i < numContributors; i++) {
      if (cs[i].contribution >= 10000) {
	cout << "  Name: " << cs[i].name
	     << ", Contribution: " << cs[i].contribution
	     << endl;
      }
      else {
	remaining[numRemaining++] = cs[i];
      }
    }
  }

  cout << "Patrons:\n";
  if (numRemaining == 0) {
    cout << "  none" << endl;
  }
  else {
    for (int i = 0; i < numRemaining; i++) {
      cout << "  Name: " << remaining[i].name
	   << ", Contribution: " << remaining[i].contribution
	   << endl;
    }
  }

  delete [] remaining;
}
