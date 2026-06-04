#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        bool found = false;

        for (long long y = 0; y * k <= n; y++) {
            long long remainder = n - y * k;
            if (remainder % 2 == 0) {
                found = true;
                break;
            }
            if (k % 2 == 0) {
                break;
            }
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}