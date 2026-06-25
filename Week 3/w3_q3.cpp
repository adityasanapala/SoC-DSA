#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    const int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);

    // Base case: 1 way to make a sum of 0
    dp[0] = 1;

    // Compute dp values up to n
    for (int i = 1; i <= n; i++) {
        for (int die = 1; die <= 6; die++) {
            if (i - die >= 0) {
                dp[i] = (dp[i] + dp[i - die]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}