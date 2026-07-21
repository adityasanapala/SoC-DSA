#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;

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
    int n;
    ll ans = 0;
    cin >> n;
    vint V(n);
    for (int i = 0; i < n; i++) { cin >> V[i]; }
    sort(V.begin(), V.end());
    int median = V[n / 2];
    for (int i = 0; i < n; i++) { ans += abs(V[i] - median); }
    cout << ans << endl;
}
