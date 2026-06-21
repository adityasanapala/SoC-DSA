#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll t,mx=0;
    cin>>t;
    vector<ll>test;
    for(int i=0;i<t;i++){
        ll x;
        cin>>x;
        test.push_back(x);
        mx=max(mx,x);
    }
    ll mod=1e9+7;
    vector<ll>nx1(mx+1,0);
    vector<ll>nx2(mx+1,0);
    nx1[1]=1;
    nx2[1]=1;
    for(int i=2;i<=mx;i++){

    }
}