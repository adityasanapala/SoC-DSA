#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        vector<ll>pos(n+1,0);
        ll l,r;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            pos[x]=i;
        }
        if(n%2==0){
            r=n/2;
            l=n/2+1;
        }
        else{
            l=(n+1)/2;
            r=(n+1)/2;
        }
        while(l>0){
            if(pos[l]>pos[l-1])l--;
            else break;
        }
        while (r<=n){
            if(pos[r]<pos[r+1])r++;
            else break;
        }
        cout<<max(l-1,n-r)<<'\n';
    }
}
//done