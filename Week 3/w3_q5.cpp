#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
long long dp[1000001][2];

void func(){
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(long long i = 2; i <= 1000001; i++){
        dp[i][0] = ((dp[i-1][0] * 4)%mod + dp[i-1][1]%mod)%mod;
        dp[i][1] = (dp[i-1][0]%mod + (2*dp[i-1][1])%mod)%mod;
    }
}

int main(){
    long long t;
    cin>>t;
    vector<long long> ans(t);
    func();
    for(long long i = 0; i < t; i++){
        long long x;
        cin>>x;
        ans[i] = (dp[x][1] + dp[x][0])%mod;
    }
    for(auto p : ans){
        cout<<p<<endl;
    }
    return 0;
}