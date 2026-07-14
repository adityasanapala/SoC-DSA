#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    if(n >= m){
        cout<<"YES"<<endl;
        return 0;
    }
    vector<bool> dp(m, false);
    for(int i = 0; i < n; i++){
        int val = a[i]%m;
        vector<bool> next_dp = dp;
        next_dp[val] = true;
        for(int j = 0; j < m; j++){
            if(dp[j]){
                next_dp[(j + val)%m] = true;
            }
        }
        dp = next_dp;
        if(dp[0]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    if(dp[0]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}