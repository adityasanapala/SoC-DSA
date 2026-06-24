#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<long long> b(m);
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }
    vector<int> dp(m, 0);
    vector<int> parent(m, -1);
    for(int i = 0; i < n; i++){
        int best = 0;
        int best_index = -1;
        for(int j = 0; j < m; j++){
            if(a[i] > b[j]){
                if(dp[j] > best){
                    best = dp[j];
                    best_index = j;
                }
            }
            else if(a[i] == b[j]){
                if(best+1 > dp[j]){
                    dp[j] = best+1;
                    parent[j] = best_index;
                }
            }
        }
    }
    int ans = 0;
    int index = -1;
    for(int i = 0; i < m; i++){
        if(dp[i] > ans){
            ans = dp[i];
            index = i;
        }
    }
    cout<<ans<<endl;
    vector<long long> res;
    while(index != -1){
        res.push_back(b[index]);
        index = parent[index];
    }
    reverse(res.begin(), res.end());
    for(auto x : res){
        cout<<x<<" ";
    }
    return 0;
}