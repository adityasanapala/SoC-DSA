#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k;
    cin>>n>>k;
    vector<long long> a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    long long max_val = -1e18;
    long long start = max(1LL, n-2*k);
    for(long long i = start; i <= n; i++){
        for(long long j = i+1; j <= n; j++){
        long long current_val = i*j-k*(a[i] | a[j]);
        max_val = max(max_val, current_val);
        }
    }
    cout<<max_val<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}