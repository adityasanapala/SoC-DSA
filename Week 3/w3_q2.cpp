#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<ll>;
using vpair = vector<pair<ll, ll>>;
ll n, tgt;

ll vmin(const vint& V) {
    ll ans;
    for (auto& i : V) { ans = min(ans, i); }
    return ans;
}

ll productsmade(ll time, const vint& V) {
    ll ans = 0;
    for (ll i = 0; i < n; i++) { ans += time / V[i]; }
    return ans;
}

int main() {
    // FACTORY MACHINES
    scanf("%lli %lli", &n, &tgt);
    vint V(n);
    for (ll i = 0; i < n; i++) { scanf("%lli", &V[i]); }
    ll tmax = vmin(V) * tgt;
    ll st = 1, end = tmax, mid = tmax / 2;
    ll ans;
    while (end >= st) {
        mid = st + (end - st) / 2;
        if (productsmade(mid, V) >= tgt) { end = mid - 1; }
        else { st = mid + 1; }
    }
    printf("%lli", mid);
}
