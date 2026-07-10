#include <iostream>
using namespace std;

int luckiness(int num) {

    int largest = 0;
    int smallest = 9;

    while (num > 0) {

        int digit = num % 10;

        if (digit > largest) {
            largest = digit;
        }

        if (digit < smallest) {
            smallest = digit;
        }

        num /= 10;
    }

    return largest - smallest;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int l, r;
        cin >> l >> r;

        int best_num = l;
        int best_luck = luckiness(l);

        for (int i = l; i <= r; i++) {

            int curr_luck = luckiness(i);

            if (curr_luck > best_luck) {
                best_luck = curr_luck;
                best_num = i;
            }

            if (best_luck == 9) {
                break;
            }
        }

        cout << best_num << endl;
    }

    return 0;
}