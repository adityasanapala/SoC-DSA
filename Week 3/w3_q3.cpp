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
    const int mod = 1e9 + 7;
    vi dp(n + 1, 0);
    dp[0]=1;
    loop(i,1,n+1){
        loop(j,1,7){
            if(i-j>=0){
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    cout<< dp[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}