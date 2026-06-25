#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    long long W;

    cin >> N >> W;

    vector<pair<long long, int>> item(N);

    int maxValue = 0;

    for (int i = 0; i < N; i++) {
        cin >> item[i].first >> item[i].second;
        maxValue += item[i].second;
    }

    const long long INF = 1e18;

    vector<long long> dp(maxValue + 1, INF);

    dp[0] = 0;

    for (int i = 0; i < N; i++) {

        long long weight = item[i].first;
        int value = item[i].second;

        for (int j = maxValue; j >= value; j--) {

            dp[j] = min(dp[j], dp[j - value] + weight);
        }
    }

    for (int v = maxValue; v >= 0; v--) {

        if (dp[v] <= W) {
            cout << v;
            break;
        }
    }

    return 0;
}