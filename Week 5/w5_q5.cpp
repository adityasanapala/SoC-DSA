#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        int64 c;
        cin >> n >> c;

        vector<int64> s(n);
        unordered_set<int64> st;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            st.insert(s[i]);
        }

        int64 total = (c + 1) * (c + 2) / 2;

        int64 badSum = 0;
        int64 badDiff = 0;
        int64 inter = 0;

        for (auto x : s) {
            badSum += x / 2 + 1;
            badDiff += c - x + 1;
        }

        for (auto a : s) {
            for (auto b : {0LL}) {} // dummy to keep formatting
        }

        for (auto a : s) {
            for (auto b : s) {
                if (a >= b && ((a - b) & 1) == 0)
                    inter++;
            }
        }

        cout << total - badSum - badDiff + inter << '\n';
    }
}