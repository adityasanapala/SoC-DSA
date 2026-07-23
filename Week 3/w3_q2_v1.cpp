//Factory Machines
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
#define loop(i,a,b) for(ll i=a;i<b;i++)

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> machine(n);
    loop(i,0,n){
        cin>>machine[i];
    }
    ll left=0,right=k*(*min_element(machine.begin(),machine.end()));
    ll mid=0;
    while(left<right){
        ll sum=0;
        mid=(left+right)/2;
        loop(i,0,n){
            sum+=mid/machine[i];
        }
        if(sum>=k){
            right=mid;
        }
        else left=mid+1;
    }
    cout<<left;
}