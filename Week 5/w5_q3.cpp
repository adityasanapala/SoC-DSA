#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        reverse(s.begin(), s.end());

        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 1;

        for (int pos = 0; pos < n; pos++) {
            int d = s[pos] - '0';

            for (int carry = 0; carry <= 1; carry++) {
                if (!dp[pos][carry]) continue;

                for (int a = 5; a <= 9; a++) {
                    for (int b = 5; b <= 9; b++) {
                        int sum = a + b + carry;

                        if (sum % 10 == d) {
                            dp[pos + 1][sum / 10] = 1;
                        }
                    }
                }
            }
        }

        cout << (dp[n][0] ? "YES" : "NO") << '\n';
    }

    return 0;
}