#include <iostream>

using namespace std;

int dp[1000005];

int main() {
    int n;
    cin >> n;

    int MOD = 1000000007;
    
    dp[0] = 1;

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