#include <iostream>

using namespace std;

long long f[1000005];
long long g[1000005];

int main() {
    int MOD = 1000000007;

    f[1] = 1;
    g[1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        f[i] = (4 * f[i - 1] + g[i - 1]) % MOD;
        g[i] = (f[i - 1] + 2 * g[i - 1]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long total = (f[n] + g[n]) % MOD;
        cout << total << "\n";
    }

    return 0;
}