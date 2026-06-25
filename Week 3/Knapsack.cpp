#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long W;
    cin >> n >> W;

    vector<pair<int,int>> a(n);

    int totalValue = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        totalValue += a[i].second;
    }

    const long long INF = 1e18;

    vector<long long> dp(totalValue + 1, INF);
    dp[0] = 0;

    for(auto [wt, val] : a) {
        for(int v = totalValue; v >= val; v--) {
            dp[v] = min(dp[v], dp[v - val] + wt);
        }
    }

    for(int v = totalValue; v >= 0; v--) {
        if(dp[v] <= W) {
            cout << v;
            return 0;
        }
    }
}