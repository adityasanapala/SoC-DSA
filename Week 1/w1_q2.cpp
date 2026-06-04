#include <iostream>
using namespace std;

int main() {
    char dna[1000000];
    cin >> dna;

    int long_rep = 1;
    int curr_rep = 1;

    for (int i = 1; dna[i] != '\0'; i++) {

        if (dna[i] == dna[i - 1]) {
            curr_rep++;
        }
        else {
            curr_rep = 1;
        }

        if (curr_rep > long_rep) {
            long_rep = curr_rep;
        }
    }

    cout << long_rep;

    return 0;
}