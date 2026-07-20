#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<ll>;
ll n, a;
ll tgt;

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

int main() {
    cin >> n >> tgt;
    bool flag = false;
    vector<pair<ll, ll>> V(n + 1);
    // V will always have V[0] but I am never accessing that.
    // I am initialising l from 1
    for (ll i = 1; i <= n; i++) {
        // printf("Visbeingprinted\n");
        cin >> a;
        V[i].first = a;
        V[i].second = i;
    }
    sort(V.begin(), V.end());
    // pprint(V);
    ll l = 1, r = n;
    while (l < r) {
        // printf("V[l].first:%lli, V[r].first:%lli\n", V[l].first, V[r].first);
        if (V[l].first + V[r].first == tgt) {
            cout << V[l].second << " " << V[r].second << endl;
            return 0;
        }
        else if (V[l].first + V[r].first > tgt) { r--; }
        else if (V[l].first + V[r].first < tgt) { l++; }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
// How the fuck is it printing 0 and 3
// why is there a value named 0,0 in here
