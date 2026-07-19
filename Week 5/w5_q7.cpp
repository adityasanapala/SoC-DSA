#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long dp[205][205][205];

int main() {
    int R, G, B;
    cin >> R >> G >> B;

    int r[R], g[G], b[B];
    for (int i = 0; i < R; i++) cin >> r[i];
    for (int i = 0; i < G; i++) cin >> g[i];
    for (int i = 0; i < B; i++) cin >> b[i];

    sort(r, r + R, greater<int>());
    sort(g, g + G, greater<int>());
    sort(b, b + B, greater<int>());

    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= G; j++) {
            for (int k = 0; k <= B; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    long long max1 = 0;

    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= G; j++) {
            for (int k = 0; k <= B; k++) {
                max1 = max(max1, dp[i][j][k]);

                if (i < R && j < G) {
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + (long long)r[i] * g[j]);
                }
                if (i < R && k < B) {
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + (long long)r[i] * b[k]);
                }
                if (j < G && k < B) {
                    dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + (long long)g[j] * b[k]);
                }
            }
        }
    }

    cout << max1 << "\n";

    return 0;
}