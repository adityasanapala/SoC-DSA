#include <iostream>
#include <vector>
using namespace std;
using vint = vector<int>;
using ll = long long;
using ct = vector<vector<int>>;

int fun(ll i, ll j, ct& v) {
    if (v[i][j] == -1) { v[i][j] = fun(i - 1, j - 2, v) | fun(i - 2, j - 1, v); }
    return v[i][j];
}

void gun(ll a, ll b) {
    if (a == 2 * b || b == 2 * a) {
        cout << "YES" << endl;
        return;
    }
    if (a == 0 || b == 0 || a == 1 || b == 1) {
        cout << "NO" << endl;
        return;
    }
    ct v(a + 1, vint(b + 1, -1));
    v[0] = vint(b + 1, 0);
    for (vint& i : v) { i[0] = 0; }
    v[0][0] = 1;

    v[1] = vint(b + 1, 0);
    for (vint& i : v) { i[1] = 0; }
    v[1][2] = 1;
    v[2][1] = 1;

    if (fun(a, b, v) == 1) {
        cout << "YES" << endl;
    } else if (fun(a, b, v) == 0) {
        cout << "NO" << endl;
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        gun(a, b);
    }
}
