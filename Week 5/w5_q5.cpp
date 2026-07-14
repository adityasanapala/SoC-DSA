#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, c;
    cin>>n>>c;
    vector<long long> v(n);
    long long even_count = 0;
    long long odd_count = 0;
    long long ans = ((c+1)*(c+2))/2;
    for(long long i = 0; i < n; i++){
        cin>>v[i];
        ans -= (v[i]/2) + 1;
        ans -= (c - v[i] + 1);
        if(v[i]%2 == 0){
            even_count++;
        }
        else{
            odd_count++;
        }
    }
    ans += (even_count * (even_count + 1))/2;
    ans += (odd_count * (odd_count + 1))/2;
    cout<<ans<<endl;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}