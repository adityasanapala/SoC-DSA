#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    
    long long a[n];
    long long pref[n + 1];
    
    pref[0] = 0;
    long long min1 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
        if (pref[i + 1] < min1) {
            min1 = pref[i + 1];
        }
    }

    if (min1 >= 0) {
        cout << power(2, n) << "\n";
        return;
    }

    long long ans = 0;
    long long cur = 1;

    for (int i = 1; i <= n; i++) {
        if (pref[i] >= 0) {
            cur = (cur * 2) % MOD;
        }
        
        if (pref[i] == min1) {
            long long rem = power(2, n - i);
            long long tot = (cur * rem) % MOD;
            ans = (ans + tot) % MOD;
        }
    }

    cout << ans << "\n";
}

int main() {  
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}