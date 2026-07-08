#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int n, m;

vector<vector<long long>> dp;

void generate(int row, int curMask, int nextMask, int col) {

    if (row == n) {
        dp[col + 1][nextMask] =
            (dp[col + 1][nextMask] + dp[col][curMask]) % MOD;
        return;
    }

    // Already occupied
    if (curMask & (1 << row)) {
        generate(row + 1, curMask, nextMask, col);
    }

    else {

        // Vertical domino
        if (row + 1 < n &&
            !(curMask & (1 << (row + 1)))) {

            generate(row + 2, curMask, nextMask, col);
        }

        // Horizontal domino
        generate(row + 1,
                 curMask,
                 nextMask | (1 << row),
                 col);
    }
}

int main() {

    cin >> n >> m;

    dp.assign(m + 1, vector<long long>(1 << n, 0));

    dp[0][0] = 1;

    for (int col = 0; col < m; col++) {

        for (int mask = 0; mask < (1 << n); mask++) {

            if (dp[col][mask] == 0)
                continue;

            generate(0, mask, 0, col);
        }
    }

    cout << dp[m][0];

    return 0;
}