#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> good(n - 1);

        for (int i = 0; i < n - 1; i++) {
            good[i] = (a[i] < 2 * a[i + 1]);
        }

        int cntBad = 0;

        for (int i = 0; i < k; i++) {
            if (!good[i]) cntBad++;
        }

        int ans = (cntBad == 0);

        for (int r = k; r < n - 1; r++) {

            if (!good[r - k]) cntBad--;
            if (!good[r]) cntBad++;

            if (cntBad == 0) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}