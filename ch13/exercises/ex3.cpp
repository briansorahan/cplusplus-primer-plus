// Exercise 3 from Chapter 13 of C++ Primer Plus
// Brian Sorahan

#include <iostream>
#include <string>
#include "dma.hpp"

const int DMAS = 4;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    abstractDMA* dmas[DMAS];
    char* temp;
    int tempnum;
    char kind;

    for (int i = 0; i < DMAS; i++) {
        cout << "Enter dma's label: ";
        cin >> temp;
        // cin.get();
        cout << "Enter dma's rating: ";
        cin >> tempnum;
        // cin.get();

        cout << "Enter 1 for baseDMA, 2 for lacksDMA, or 3 for hasDMA: ";
        while (cin >> kind && (kind != '1' && kind != '2' && kind != '3')) {
            cout << "Please enter either 1, 2, or 3: ";
        }

        switch(kind) {
        case '1':
            dmas[i] = new baseDMA(temp, tempnum);
            break;
        case '2':
            char tempcolor[80];
            cout << "Enter the color: ";
            cin >> tempcolor;
            dmas[i] = new lacksDMA(tempcolor, temp, tempnum);
            break;
        case '3':
            char tempstyle[80];
            cout << "Enter the style: ";
            cin >> tempstyle;
            dmas[i] = new hasDMA(tempstyle, temp, tempnum);
            break;
        }

        while (cin.get() != '\n')
            continue;
    }

    cout << endl;
    for (int i = 0; i < DMAS; i++) {
        dmas[i]->ViewDMA();
        // cout << dmas[i] << endl;
    }

    for (int i = 0; i < DMAS; i++) {
        delete dmas[i];
    }

    cout << "Done.\n";
    return 0;
}
