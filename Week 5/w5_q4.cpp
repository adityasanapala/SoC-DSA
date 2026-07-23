#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int64 a, b;
        cin >> a >> b;

        int64 ans = (1LL << 60);

        for (int64 k = 1; k <= 45000; k++) {
            int64 cur = (k - 1)
                      + (a + k - 1) / k
                      + (b + k - 1) / k;
            ans = min(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}