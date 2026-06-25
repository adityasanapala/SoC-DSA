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

void solve() {
    int n;
    cin >> n;
    vi a(n),d(n);
    loop(i,0,n){
        cin >> a[i] >> d[i];
    }
    int sum = 0;
    loop(i,0,n){
        sum += d[i] - a[i];
    }
    sort(all(a));
    int diff = 0; // time difference
    loop(i,0,n){
        diff += (n - 1 - i) * a[i];
    }
    cout << sum - diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}