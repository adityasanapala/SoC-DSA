#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
    ll x,n;
    cin>>x>>n;
    priority_queue<ll,vector<ll>,greater<ll>> d;
    for(int i=0;i<n;i++){
        ll y;
        cin>>y;
        d.push(y);
    }
    ll cost=0;
    while(d.size()>1){
        ll a=d.top();
        d.pop();
        ll b=d.top();
        d.pop();
        d.push(a+b);
        cost+=a+b;
    }
    cout<<cost;
}
//done