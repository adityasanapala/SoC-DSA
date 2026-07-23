//Stick Divisions

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define loop(i,a,b) for(ll i=a;i<b;i++)
//Greedy-choose smallest stick 1st
//1st merged stick contributes to cost multiple times
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x,n,a,cost=0,first=0,second=0;
    cin>>x>>n;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i=0;i<n;i++){
        cin>>a;
        pq.push(a);
    }
    while(pq.size()>1){
        first=pq.top();
        pq.pop();
        second=pq.top();
        pq.pop();
        cost = cost + first + second;
        pq.push(first + second);
    }
    cout<<cost<<"\n";
}
