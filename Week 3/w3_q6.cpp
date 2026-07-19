#include <iostream>
#include <algorithm>

using namespace std;

long long dp[100005];

int main() {
    int n;
    long long W;
    cin >> n >> W;

    int max = n * 1000;
    long long qwer = 1e15;

    for (int i = 1; i <= max; i++) {
        dp[i] = qwer;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        long long w;
        int v;
        cin >> w >> v;

        for (int j = max; j >= v; j--) {
            if (dp[j - v] != qwer) {
                dp[j] = min(dp[j], dp[j - v] + w);
            }
        }
    }

    int ans = 0;
    for (int j = max; j >= 0; j--) {
        if (dp[j] <= W) {
            ans = j;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}