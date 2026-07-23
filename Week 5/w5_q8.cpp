#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << "YES\n";
        return 0;
    }

    vector<int> dp(m, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x %= m;

        vector<int> ndp = dp;

        ndp[x] = 1;

        for (int r = 0; r < m; r++) {
            if (dp[r]) {
                ndp[(r + x) % m] = 1;
            }
        }

        dp = ndp;
    }

    cout << (dp[0] ? "YES" : "NO") << '\n';

    return 0;
}