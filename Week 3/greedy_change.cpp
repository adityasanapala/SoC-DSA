#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int limit = coins[0] + coins[1];

    vector<int> dp(limit + 1, 1e9);

    dp[0] = 0;

    for (int sum = 1; sum <= limit; sum++) {

        for (int i = 0; i < n; i++) {

            if (sum >= coins[i]) {

                dp[sum] = min(dp[sum], dp[sum - coins[i]] + 1);
            }
        }
    }

    for (int x = 1; x <= limit; x++) {

        int temp = x;
        int greedy = 0;

        for (int i = 0; i < n; i++) {

            greedy += temp / coins[i];
            temp %= coins[i];
        }

        if (greedy != dp[x]) {

            cout << x << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}