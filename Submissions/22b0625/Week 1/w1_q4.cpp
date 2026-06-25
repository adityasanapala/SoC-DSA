#include <iostream>
#include <algorithm>
using namespace std;

int luck(long long x) {
    int mn = 9, mx = 0;

    while (x) {
        int d = x % 10;
        mn = min(mn, d);
        mx = max(mx, d);
        x /= 10;
    }

    return mx - mn;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long l, r;
        cin >> l >> r;

        long long ans = l;
        int best = luck(l);

        for (long long i = max(l, r - 100); i <= r; i++) {
            int cur = luck(i);

            if (cur > best) {
                best = cur;
                ans = i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}