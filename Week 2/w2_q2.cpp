#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    map<int,int> m;
    for (int i = 0; i < n;i++){
        auto it = m.find(x - a[i]);
        if (it != m.end()){
            cout << it->second << ' ' << i + 1 << endl;
            return;
        }
        m[a[i]] = i+1;
    }
    cout << "IMPOSSIBLE" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}