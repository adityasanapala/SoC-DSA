#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<ll>;
using vpair = vector<pair<ll, ll>>;

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
    ll time = 0, ans = 0;
    vpair V(n);
    for (auto& i : V) { cin >> i.first >> i.second; }
    sort(V.begin(), V.end());
    for (auto& i : V) {
        time += i.first;
        ans += i.second - time;
    }
    cout << ans;
}
