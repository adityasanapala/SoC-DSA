#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long power(long long b, long long e) {
    b %= MOD;
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> pref(n);
        long long sum = 0, mn = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            sum += x;
            pref[i] = sum;
            mn = min(mn, sum);
        }

        long long ans;
        if (mn >= 0) {
            ans = power(2, n);
        } else {
            ans = 0;
            long long nonnegBefore = 0;
            for (int j = 0; j < n; j++) {
                if (pref[j] == mn) {
                    ans = (ans + power(2, nonnegBefore + (n - 1 - j))) % MOD;
                }
                if (pref[j] >= 0) nonnegBefore++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
