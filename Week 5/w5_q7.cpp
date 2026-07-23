#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, G, B;
    cin >> R >> G >> B;

    vector<int> r(R), g(G), b(B);

    for (int &x : r) cin >> x;
    for (int &x : g) cin >> x;
    for (int &x : b) cin >> x;

    sort(r.rbegin(), r.rend());
    sort(g.rbegin(), g.rend());
    sort(b.rbegin(), b.rend());

    static ll dp[205][205][205];

    ll ans = 0;

    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= G; j++) {
            for (int k = 0; k <= B; k++) {

                ans = max(ans, dp[i][j][k]);

                if (i < R && j < G)
                    dp[i + 1][j + 1][k] = max(
                        dp[i + 1][j + 1][k],
                        dp[i][j][k] + 1LL * r[i] * g[j]);

                if (i < R && k < B)
                    dp[i + 1][j][k + 1] = max(
                        dp[i + 1][j][k + 1],
                        dp[i][j][k] + 1LL * r[i] * b[k]);

                if (j < G && k < B)
                    dp[i][j + 1][k + 1] = max(
                        dp[i][j + 1][k + 1],
                        dp[i][j][k] + 1LL * g[j] * b[k]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}