#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int ok[n];
    for (int i = 0; i < n-1;i++){
        ok[i] = (2 * a[i+1] > a[i]);
    }
    int tot = 0;
    for (int i = 0; i < k;i++){
        tot += ok[i];
    }
    int ans = 0;
    if(tot==k){
        ans++;
    }
    for (int i = k; i < n - 1;i++){
        tot += ok[i];
        tot -= ok[i - k];
        if(tot==k){
            ans++;
        }
    }
    cout << ans << endl;
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