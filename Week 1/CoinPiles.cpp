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
// Unfortunately I am unable to modify the container

void vprint(vector<int>& v) {
    for (int& i : v) { cout << i << " "; }
    cout << "\n";
}

void cprint(ct& v) {
    for (vector<int>& i : v) { vprint(i); }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int a = 3, b = 6;
        // cin >> a >> b;
        ct v(a + 1, vector<int>(b + 1, -1));
        v[0] = vint(b + 1, 0);
        v[1] = vint(b + 1, 0);
        for (vint& i : v) { i[0] = 0; }
        for (vint& i : v) { i[1] = 0; }
        v[0][0] = 1;
        v[1][2] = 1;
        v[2][1] = 1;
        cprint(v);
        cout << "ans: " << endl;
        cout << fun(a, b, v) << endl;
        cout << endl;
        cprint(v);
    }
}
