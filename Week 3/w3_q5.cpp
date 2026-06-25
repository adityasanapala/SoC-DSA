#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define loop(i, a, b) for (int i = a; i < b; i++)
#define input(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define pb(a) push_back(a)
#define all(a) (a).begin(), (a).end()

//If i write 1e9+7 and 1e6 instead of these large numbers i am getting TLE couldn't understand why
const int mod =1000000007;
const int mx=1000000;
int dp[mx+1][2];
void solve(){
    dp[1][0] = 1;
    dp[1][1] = 1;
    loop(i, 2, mx+1){
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % mod;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    int t = 1;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
    return 0;
}