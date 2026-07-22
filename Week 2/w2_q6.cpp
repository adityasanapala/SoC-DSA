#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    int l = (n + 1) / 2;
    int r = (n + 2) / 2;
    while (l > 0 && (l == r || (pos[l] < pos[l + 1] && pos[r - 1] < pos[r]))) {
        --l;
        ++r;
    }
    cout << (n - r + l + 1) / 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}