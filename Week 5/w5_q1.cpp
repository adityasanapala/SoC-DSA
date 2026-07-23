#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<int> dp(n, 0);
    stack<int> st;

    int mx = 0;
    int cnt = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                int j = st.top();
                st.pop();

                dp[i] = i - j + 1;

                if (j > 0)
                    dp[i] += dp[j - 1];

                if (dp[i] > mx) {
                    mx = dp[i];
                    cnt = 1;
                } else if (dp[i] == mx) {
                    cnt++;
                }
            }
        }
    }

    if (mx == 0)
        cout << "0 1\n";
    else
        cout << mx << " " << cnt << "\n";

    return 0;
}