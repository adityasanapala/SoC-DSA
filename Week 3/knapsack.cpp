#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long n,w;
cin >> n >> w;
int max_val = 100000;
long long inf = 1e18;
vector<long long> dp(max_val+5, inf);
dp[0]=0;
for(int i=0;i<n;i++){
    long long wt;
    int v;
    cin >> wt >> v;
    
    for(int j=max_val;j >=v; j--){
        if(dp[j-v]!=inf){
            dp[j]=min(dp[j],dp[j-v]+wt);
        }
    }
}
long long ans = 0;
for(int j=max_val;j>=0;j--){
    if(dp[j]<=w){
        ans = j;
        break;
    }
}
cout<<ans;
return 0;

}