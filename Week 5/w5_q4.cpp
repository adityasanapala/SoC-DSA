#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    long long min1 = a + b; 

    for (long long m = 1; m <= 100000; ++m) {
        long long cur = (m - 1) + (a + m - 1) / m + (b + m - 1) / m;
        if (cur < min1) {
            min1 = cur;
        }
    }

    cout << min1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}