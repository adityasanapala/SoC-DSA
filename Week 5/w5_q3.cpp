#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int L = (int)s.size();

        bool ok = (L >= 2) && (s[0] == '1') && (s[L - 1] != '9');
        for (int i = 1; ok && i < L - 1; i++) {
            if (s[i] == '0') ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
