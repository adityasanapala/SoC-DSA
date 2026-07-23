#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<ll>;
using vpair = vector<pair<ll, ll>>;
ll M = 1e9 + 7;

template <typename T>
void vprint(const T& v) {
    for (const auto& i : v) { cout << i << " "; }
    cout << "\n";
}

template <typename T>
void pprint(const T& v) {
    for (const auto& i : v) { cout << i.first << " " << i.second << "\n"; }
    cout << "\n";
}

int main() {
    ll n;
    cin >> n;
    vint V(n + 1, 0);
    for (ll i = 1; i <= 6 && i <= n; i++) { V[i] += 1; }
    for (ll i = 1; i <= n; i++) {
        for (ll j = i - 1; j >= i - 6 && j > 0; j--) { V[i] += (V[j] % M); }
    }
    cout << V[n] % M;
    // DONE
    // NOw I need to take mod
}
