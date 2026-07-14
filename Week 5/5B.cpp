#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> P1(n + 1, 0);
    vector<int> P2(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        P1[i + 1] = P1[i] + (a[i] == 1 ? 1 : -1);
        P2[i + 1] = P2[i] + (a[i] != 3 ? 1 : -1);
    }

    vector<int> suf_max_P2(n, -1e9);
    suf_max_P2[n - 1] = P2[n - 1];
    for (int i = n - 2; i >= 2; --i) {
        suf_max_P2[i] = max(P2[i], suf_max_P2[i + 1]);
    }

    bool possible = false;
    for (int i = 0; i <= n - 3; ++i) {
        if (P1[i + 1] >= 0 && suf_max_P2[i + 2] >= P2[i + 1]) {
            possible = true;
            break;
        }
    }

    if (possible) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}