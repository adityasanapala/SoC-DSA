//Tasks and Deadlines

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int main(){
    ll n,finish=0,deadlines_sum=0,d=0;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i]>>d;
        deadlines_sum+=d;
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++){
        finish+=v[i]*(n-i);
    }
    cout<<deadlines_sum-finish;
}