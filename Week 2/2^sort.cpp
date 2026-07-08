#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> good(n - 1);

        for (int i = 0; i < n - 1; i++)
            good[i] = (a[i] < 2LL * a[i + 1]);

        int cnt = 0;

        // first window
        for (int i = 0; i < k; i++)
            cnt += good[i];

        int ans = (cnt == k);

        // slide
        for (int i = k; i < n - 1; i++) {
            cnt += good[i];
            cnt -= good[i - k];

            if (cnt == k)
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}