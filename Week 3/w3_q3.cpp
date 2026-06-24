#include<bits/stdc++.h>
using namespace std;

long long mod = pow(10, 9) + 7;

int main(){
    long long n;
    cin>>n;
    vector<long long> dp(n+1);
    dp[0] = 1;
    for(long long i = 1; i <= n; i++){
        for(long long j = 1; j <= 6; j++){
            if(j <= i) dp[i] = (dp[i] + dp[i-j])%mod;
        }
    }
    cout<<dp[n]%mod<<endl;
    return 0;
}