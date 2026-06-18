#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long W;
    scanf("%d %lld", &n, &W);
    vector<long long> w(n);
    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld %d", &w[i], &v[i]);
        total += v[i];
    }

    const long long INF = 1e18;
    vector<long long> dp(total + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = total; j >= v[i]; j--)
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);

    int ans = 0;
    for (int j = total; j >= 0; j--)
        if (dp[j] <= W) { ans = j; break; }
    printf("%d\n", ans);
    return 0;
}
