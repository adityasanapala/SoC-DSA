//Counting Towers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define MOD 1000000007

//Tabulation

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    vector<ll> testcases(t);
    loop(i,0,t){
        cin >> testcases[i];
    }
    ll n = *max_element(testcases.begin(),testcases.end());
    vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
        dp[1][0]=1;
        dp[1][1]=1;
    loop(i,2,n+1){
        dp[i][0]= (2 * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1]= (4 * dp[i-1][1] + dp[i-1][0]) % MOD;
    }
    loop(i,0,t){
        cout<<(dp[testcases[i]][0] + dp[testcases[i]][1])%MOD<<"\n";
    }
}
/*State - Q was asking abt Total no. of ways of building ht n tower 
          but if we already know ans for n-1, the choices we have later depends on
          whether last block of n-1 tower is split or merged,if split we cant 
          extend coz vertical line will be left.So 2 states
Recurrence - from n-1 tower last block merged(no vertical line)-2 n merged and 1 n split tower
             can be built,from n-1 split tower-4 n split tower and 1 merged tower can be created
             
*/
