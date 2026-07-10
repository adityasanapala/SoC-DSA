#include <iostream>
#include <string>
using namespace std;

int main() {
    string dna;
    cin >> dna;

    int maxCount = 1;
    int count = 1;

    for (int i = 1; i < dna.length(); i++) {
        if (dna[i] == dna[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }

    cout << maxCount << endl;

    return 0;
}