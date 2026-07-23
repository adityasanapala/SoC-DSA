//Die Combinations

#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

int main(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(ll j=1;j<n+1;j++){
    for(ll i=1;i<=6;i++){
        if(j-i>=0)dp[j]+=dp[j-i]%1000000007;
    }
    }
    cout<<dp[n]%(1000000007);
}
