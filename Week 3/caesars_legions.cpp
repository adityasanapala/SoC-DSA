#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000000;

int dp[101][101][11][11];

int main() {

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    dp[0][0][0][0] = 1;

    for (int f = 0; f <= n1; f++) {

        for (int h = 0; h <= n2; h++) {

            for (int cf = 0; cf <= k1; cf++) {

                for (int ch = 0; ch <= k2; ch++) {

                    int cur = dp[f][h][cf][ch];

                    if (cur == 0)
                        continue;

                    // Place footman
                    if (f < n1 && cf < k1) {

                        dp[f + 1][h][cf + 1][0] += cur;
                        dp[f + 1][h][cf + 1][0] %= MOD;
                    }

                    // Place horseman
                    if (h < n2 && ch < k2) {

                        dp[f][h + 1][0][ch + 1] += cur;
                        dp[f][h + 1][0][ch + 1] %= MOD;
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int cf = 0; cf <= k1; cf++) {

        for (int ch = 0; ch <= k2; ch++) {

            ans += dp[n1][n2][cf][ch];
            ans %= MOD;
        }
    }

    cout << ans;

    return 0;
}