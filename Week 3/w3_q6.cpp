#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    long long W;
    cin >> n >> W;
    int maxVal = n * 1000; 
    // adjust 1000 to the actual max per-item value bound
    const long long INF = 1e15;

    vector<long long> dp(maxVal + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        long long w;
        int v;
        cin >> w >> v;
        for (int j = maxVal; j >= v; j--) {
            if (dp[j - v] != INF) {
                dp[j] = min(dp[j], dp[j - v] + w);
            }
        }
    }

    int ans = 0;
    for (int j = maxVal; j >= 0; j--) {
        if (dp[j] <= W) {
            ans = j;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}