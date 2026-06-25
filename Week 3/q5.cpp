#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    const long long mod = 1e9 +7;
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        long long dp0[n],dp1[n];
        dp0[0]=1,dp1[0]=1;
        for(long i=0;i<n-1;i++){
            dp0[i+1]=(4*dp0[i]+dp1[i])%mod;
            dp1[i+1]=(dp0[i]+2*dp1[i])%mod;
        }
        cout<<(dp0[n-1]+dp1[n-1])%mod<<"\n";

    }
    return 0;
}