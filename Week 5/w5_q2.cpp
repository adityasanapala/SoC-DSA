#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
#define pb(a) push_back(a)
#define all(a) (a).begin(),(a).end()

const int MOD = 998244353;
vi p2(400005);
void precompute(){
    p2[0] = 1;
    for (int i = 1; i < 400005; i++){
        p2[i] = (p2[i - 1] * 2) % MOD;
    }
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    input(a, n);
    int sum = 0;
    int mn = 0;
    loop(i, 0, n){
        sum += a[i];
        mn = min(mn, sum);
    }
    if (mn == 0){
        cout << p2[n] << endl;
        return;
    }
    sum = 0;
    int ans = 0;
    int cnt = 0;
    loop(i, 0, n){
        sum += a[i];
        if (sum == mn){
            ans = (ans + p2[n-i+cnt-1]) % MOD;
        }
        if (sum >= 0) {
            cnt++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}