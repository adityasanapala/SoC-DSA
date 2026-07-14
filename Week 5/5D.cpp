#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    
    vector<int> pa(n), pb(m);
    pa[0] = (a[0] - '0') % 10;
    for (int i = 1; i < n; ++i) {
        pa[i] = (pa[i - 1] + a[i] - '0') % 10;
    }
    
    pb[0] = (b[0] - '0') % 10;
    for (int i = 1; i < m; ++i) {
        pb[i] = (pb[i - 1] + b[i] - '0') % 10;
    }

    if (pa[n - 1] != pb[m - 1]) {
        cout << -1 << "\n";
        return;
    }

    vector<int> dp(m - 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int prev = 0;
        for (int j = 0; j < m - 1; ++j) {
            int temp = dp[j];
            if (pa[i] == pb[j]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(dp[j], (j > 0 ? dp[j - 1] : 0));
            }
            prev = temp;
        }
    }
    
    int ans = 1;
    if (m - 1 > 0) {
        ans += dp[m - 2];
    }
    
    cout << ans << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}