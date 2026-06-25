
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long W;
    cin >> N >> W;

    vector<long long> w(N);
    vector<int> v(N);

    int maxValue = 0;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
        maxValue += v[i];
    }

    const long long INF = 1e18;

    vector<long long> dp(maxValue + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int val = maxValue; val >= v[i]; val--) {
            dp[val] = min(dp[val],
                          dp[val - v[i]] + w[i]);
        }
    }

    int ans = 0;

    for (int val = maxValue; val >= 0; val--) {
        if (dp[val] <= W) {
            ans = val;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}