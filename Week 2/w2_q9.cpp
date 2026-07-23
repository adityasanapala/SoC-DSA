#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int main(){
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll>> v(n);
    vector<ll> itcontains(n,0);
    vector<ll> containedby(n,0);

    for(int i=0;i<n;i++){
        cin>>get<0>(v[i])>>get<1>(v[i]);
        get<2>(v[i])=i;
    }
    
    sort(v.begin(), v.end(), [](auto a, auto b) {
    if (get<0>(a) == get<0>(b))
        return get<1>(a) >= get<1>(b);
    return get<0>(a) < get<0>(b);
    });
    //to do
    for(int i=0;i<n;i++){

    }


    for(int i=0;i<n;i++){
        cout<<itcontains[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<containedby[i]<<" ";
    }
}