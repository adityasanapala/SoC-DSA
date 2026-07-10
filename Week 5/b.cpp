#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> p1(n + 1, 0), p2(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            p1[i] = p1[i - 1] + (a[i] == 1 ? 1 : -1);
            p2[i] = p2[i - 1] + (a[i] == 3 ? -1 : 1);
        }

        vector<int> sufMax(n + 2, INT_MIN);

        sufMax[n - 1] = p2[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i + 1], p2[i]);
        }

        bool ok = false;

        for (int x = 1; x <= n - 2; x++) {
            if (p1[x] >= 0) {
                // y must lie in [x+1, n-1]
                if (sufMax[x + 1] >= p2[x]) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}