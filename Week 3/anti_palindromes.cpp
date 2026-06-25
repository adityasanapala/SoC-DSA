#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        if (n % 2) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        int maxFreq = *max_element(freq.begin(), freq.end());

        if (maxFreq > n / 2) {
            cout << -1 << "\n";
            continue;
        }

        int bad = 0;
        vector<int> cnt(26, 0);

        for (int i = 0; i < n / 2; i++) {

            if (s[i] == s[n - 1 - i]) {
                bad++;
                cnt[s[i] - 'a']++;
            }
        }

        int mx = *max_element(cnt.begin(), cnt.end());

        cout << max(mx, (bad + 1) / 2) << "\n";
    }

    return 0;
}