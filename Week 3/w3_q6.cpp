#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, w;
    cin>>n>>w;
    vector<pair<long long, long long>> v;
    for(long long i = 0; i < n; i++){
        long long x, y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    long long mv = 100000;
    vector<long long> dp(mv + 1, 1e18);
    dp[0] = 0;
    for(long long i = 0; i < n; i++){
        long long a = v[i].first;
        long long b = v[i].second;
        for(long long j = mv; j >= b; j--){
            dp[j] = min(dp[j], dp[j-b] + a);
        }
    }
    long long ans = 0;
    for(long long j = 0; j <= mv; j++){
        if(dp[j] <= w){
            ans = j;
        }
    }
    cout<<ans<<endl;
    return 0;
}