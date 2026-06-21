#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,reward=0;
    cin>>n;
    vector<ll>a;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        reward+=y;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        reward=reward-(n-i)*a[i];
    }
    cout<<reward<<endl;
}
//done