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

        int cnt = 0;

        for (int i = 0; i < k; i++)
            if (a[i] < 2LL * a[i + 1])
                cnt++;

        int ans = (cnt == k);

        for (int i = k; i < n - 1; i++) {
            if (a[i] < 2LL * a[i + 1])
                cnt++;

            if (a[i - k] < 2LL * a[i - k + 1])
                cnt--;

            if (cnt == k)
                ans++;
        }

        cout << ans << '\n';
    }
}