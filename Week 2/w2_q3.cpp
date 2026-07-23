//Sum of three values

#include <iostream>
#include <vector>
#include <algorithm>
using ll= long long;
using namespace std;

int main(){
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    
    for(ll i=0;i<n;i++){
        ll l=i+1,r=n-1;
        while(l<r){
            if(v[i].first+v[l].first+v[r].first == x){
                cout<<v[i].second<<" "<<v[l].second<<" "<<v[r].second;
                return 0;
            }
            else if(v[i].first+v[l].first+v[r].first < x)l++;
            else r--;
        }
    }
    cout<<"IMPOSSIBLE";
}