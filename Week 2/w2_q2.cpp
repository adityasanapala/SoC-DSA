//Sum of Two Values

#include <iostream>
#include <map>
using ll= long long;
using namespace std;

int main(){
    map<ll,ll> mp;
    ll n,x;
    cin>>n>>x;

    for(ll i=0;i<n;i++){
        ll y;
        cin>>y;
        if(mp.count(x-y)){
            cout<<mp[x-y]+1<<" "<<i+1;
            return 0;
        }
         mp[y]=i;
    }

    cout<<"IMPOSSIBLE";
}