#include <iostream>
#include <vector>
using namespace std ;
using ll= long long;

int main(){
    ll n, result=0;
    cin>>n;
    vector<ll> v(n);
    cin>>v[0];
    for(ll i=1;i<n;i++){
        cin>>v[i];
        while(v[i-1]>v[i]){
            v[i]=v[i-1];
            result+=v[i-1]-v[i];
        }
    }
    cout<<result;
}