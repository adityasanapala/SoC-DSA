#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for (int mx = -30; mx <= 30; mx++) {

        int cur = INT_MIN;

        for (int i = 0; i < n; i++) {

            if (a[i] > mx) {
                cur = INT_MIN;
                continue;
            }

            if (cur == INT_MIN)
                cur = a[i];
            else
                cur = max(a[i], cur + a[i]);

            ans = max(ans, cur - mx);
        }
    }

    cout << ans << "\n";
}