#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    cin >> n;

    for(long long k = 1; k <= n; k++) {

        // total ways to place 2 knights
        long long totalWays = (k * k) * (k * k - 1) / 2;

        // attacking positions
        long long attackingWays = 4 * (k - 1) * (k - 2);

        cout << totalWays - attackingWays << endl;
    }

    return 0;
}