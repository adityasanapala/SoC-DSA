#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;
const int MOD = 1e9 + 7;

// dp[i][0] -> number of towers of height i ending with 2 separate width-1 blocks
// dp[i][1] -> number of towers of height i ending with 1 unified width-2 block
long long dp[MAXN + 1][2];

void precompute() {
    // Base cases for height 1
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        // State transitions with modulo arithmetic
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
    }
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            long long total_towers = (dp[n][0] + dp[n][1]) % MOD;
            cout << total_towers << "\n";
        }
    }

    return 0;
}