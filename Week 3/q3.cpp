#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    long n;
    cin>>n;
    long long dp[n+1];
    long long mod = 1e9 +7;
    dp[0]=1;
    for(long i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=6;j++){
            if(i>=j){
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}