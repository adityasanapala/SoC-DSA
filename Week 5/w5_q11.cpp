#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1000000007;
const int MAX = 400005;

ll fact[MAX], invFact[MAX];

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);

    for (int i = MAX - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;

    int n;
    cin >> n;

    ll ans = 0;

    for (int i = 0; i <= n; i++) {
        int a;
        cin >> a;
        ans = (ans + C(i + a, i + 1)) % MOD;
    }

    cout << ans << '\n';

    return 0;
}