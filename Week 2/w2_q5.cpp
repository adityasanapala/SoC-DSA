#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n;i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int median = p[n / 2];
    int cost=0;
    for (int i = 0; i < n;i++){
        cost += abs(p[i] - median);
    }
    cout << cost << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}