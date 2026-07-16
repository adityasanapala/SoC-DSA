#include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  #include <set>
using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll W;
    cin >> N >> W;

    vector<pair<int,int>> items(N);

    int maxValue = 0;

    for (int i = 0; i < N; i++) {
        cin >> items[i].first >> items[i].second;
        maxValue += items[i].second;
    }

    vector<ll> dp(maxValue + 1, INF);
    dp[0] = 0;

    for (auto [weight, value] : items) {
        for (int v = maxValue; v >= value; v--) {
            dp[v] = min(dp[v], dp[v - value] + weight);
        }
    }

    for (int v = maxValue; v >= 0; v--) {
        if (dp[v] <= W) {
            cout << v << '\n';
            return 0;
        }
    }
}
