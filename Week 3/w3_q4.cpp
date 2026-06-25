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
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int dis = 0;
    int n1 = s1.length();
    int n2 = s2.length();
    vvi dp(n1+1, vi(n2+1));
    loop(i,0,n1+1){
        loop(j,0,n2+1){
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j]=i;
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
    }
    cout<<dp[n1][n2]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}