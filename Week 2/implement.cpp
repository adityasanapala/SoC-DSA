#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<ll>;

template <typename T>
void vprint(T& V) {
    for (auto& i : V) { cout << i << " "; }
    cout << "\n";
}

template <typename T>
void pprint(T& P) {
    for (auto& i : P) { cout << i.first << " " << i.second << "\n"; }
    cout << "\n";
}

bool issorted(vint& V) {
    for (ll i = 1; i < V.size(); i++) {
        if (V[i] != i) { return false; }
    }
    return true;
}

int main() {
    ll n, a, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = n;
        vint P(n + 1);
        for (ll i = 1; i <= n; i++) {
            cin >> a;
            P[a] = i;
        }
        ll x = 0;
        ll y = 1;
        if (issorted(P)) {
            cout << 0 << endl;
            continue;
        }
        while (y < n) {
            if (P[y + 1] > P[y]) { y++; }
            else {
                ans = min(ans, max(x, n - y));
                x = y;
                y = y + 1;
            }
        }
        cout << ans << endl;
    }
}
// 5
// 1 5 4 2 3
